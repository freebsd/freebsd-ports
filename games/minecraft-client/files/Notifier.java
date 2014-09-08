import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.Icon;
import java.awt.EventQueue;

public class Notifier extends JFrame{
    
    //Using a standard Java icon
    private Icon optionIcon = UIManager.getIcon("FileView.computerIcon");
    
    public static void main(String[] args) {
     
     EventQueue.invokeLater(new Runnable()
     {
         public void run()
         {
             //create GUI frame
             new Notifier().setVisible(true);          
         }
     });
              
    }
    
    public Notifier()
    {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setTitle("Simple Dialog Box Example");
        //setSize(500,500);
        
        setLocationRelativeTo(null); 
        
        // Show our warning to first time users
        JOptionPane.showMessageDialog(this, "Before starting MineCraft, be sure to open your Profile and set the Java Executable to: '%%PREFIX%%/share/minecraft-client/minecraft-runtime'" 
                ,"Important Notification", JOptionPane.PLAIN_MESSAGE);

	System.exit(0);
        
    }
}
