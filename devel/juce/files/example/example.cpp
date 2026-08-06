#include <juce_gui_extra/juce_gui_extra.h>

// 1. Your layout component class
class SimpleGuiComponent  : public juce::Component
{
public:
    SimpleGuiComponent()
    {
        welcomeLabel.setText("Hello, JUCE World!", juce::dontSendNotification);
        welcomeLabel.setFont(juce::FontOptions(24.0f, juce::Font::bold));
        welcomeLabel.setJustificationType(juce::Justification::centred);
        addAndMakeVisible(welcomeLabel);

        actionButton.setButtonText("Click Me!");
        actionButton.onClick = [this]() {
            welcomeLabel.setText("Button Clicked!", juce::dontSendNotification);
        };
        addAndMakeVisible(actionButton);
        setSize(400, 300);
    }

    void paint(juce::Graphics& g) override {
        g.fillAll(juce::Colours::darkgrey.darker(0.5f));
    }

    void resized() override {
        auto area = getLocalBounds();
        area.reduce(20, 20);
        welcomeLabel.setBounds(area.removeFromTop(area.getHeight() * 0.6f));
        actionButton.setBounds(area.withSizeKeepingCentre(150, 40));
    }

private:
    juce::Label welcomeLabel;
    juce::TextButton actionButton;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleGuiComponent)
};

// 2. The Window wrapper required to run the UI component on a desktop
class MainWindow    : public juce::DocumentWindow
{
public:
    MainWindow (juce::String name) : DocumentWindow (name, juce::Colours::lightgrey, DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar(true);
        setContentOwned(new SimpleGuiComponent(), true);
        setResizable(true, true);
        centreWithSize(getWidth(), getHeight());
        setVisible(true);
    }

    void closeButtonPressed() override {
        juce::JUCEApplication::getInstance()->systemRequestedQuit();
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};

// 3. The Framework process runner providing the entry point ('main')
class SimpleGuiApplication : public juce::JUCEApplication
{
public:
    SimpleGuiApplication() {}
    const juce::String getApplicationName() override       { return "SimpleGuiApp"; }
    const juce::String getApplicationVersion() override    { return "1.0.0"; }
    void initialise (const juce::String&) override        { mainWindow.reset(new MainWindow("Simple JUCE GUI")); }
    void shutdown() override                               { mainWindow.reset(); }
    void systemRequestedQuit() override                    { quit(); }

private:
    std::unique_ptr<MainWindow> mainWindow;
};

// Start macro that expands into the platform-native main() loop function
START_JUCE_APPLICATION (SimpleGuiApplication)

