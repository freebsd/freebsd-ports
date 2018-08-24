Fix build with older Vala versions

../src/CategoryView.vala:75.24-75.30: error: The name `ACTIONS' does not exist in the context of `CategoryView.icons'
            category = ACTIONS
                       ^^^^^^^
../src/CategoryView.vala:75.13-75.30: error: Invalid type for member `category'
            category = ACTIONS
            ^^^^^^^^^^^^^^^^^^

https://github.com/danrabbit/lookbook/issues/33

--- src/CategoryView.vala.orig	2018-08-23 23:19:38 UTC
+++ src/CategoryView.vala
@@ -72,2188 +72,2188 @@ public class CategoryView : Gtk.Paned {
         Icon () {
             name = "address-book-new",
             description = _("Create a new address book"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "align-horizontal-center",
             description = _("Align objects to center along the X axis"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "align-horizontal-left",
             description = _("Align objects left along the X axis"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "align-horizontal-right",
             description = _("Align objects right along the X axis"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "align-vertical-bottom",
             description = _("Align objects to bottom along the Y axis"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "align-vertical-center",
             description = _("Align objects to center along the Y axis"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "align-vertical-top",
             description = _("Align objects to top along the Y axis"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "application-exit",
             description = _("Used for exiting an application"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "appointment-new",
             description = _("Create a new appointment in a calendaring application"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "bookmark-new",
             description = _("Create a new bookmark"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "call-start",
             description = _("Initiate or accept a call"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "call-stop",
             description = _("Stop the current call"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "changes-allow",
             description = _("Allow changes by unlocking such as with a password"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "changes-prevent",
             description = _("Prevent changes by locking such as with a password"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "contact-new",
             description = _("Create a new contact in an address book application"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-export",
             description = _("Export a document"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-import",
             description = _("Import a document"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-new",
             description = _("Create a new document"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-open",
             description = _("Open a document"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-open-recent",
             description = _("Open a document that was recently opened"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-page-setup",
             description = _("The page setup action of a document editor"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-print",
             description = _("Print"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-print-preview",
             description = _("The print preview action of an application"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-properties",
             description = _("View the properties of a document"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-revert",
             description = _("Revert to a previous version of a document"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-save",
             description = _("Save"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-save-as",
             description = _("Save as"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "document-send",
             description = _("Send"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit",
             description = _("Edit"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-clear",
             description = _("Clear"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-copy",
             description = _("Copy"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-cut",
             description = _("Cut"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-delete",
             description = _("Delete"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-find",
             description = _("Find"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-find-replace",
             description = _("Find & Replace"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-flag",
             description = _("Flag an item, such as a spam email"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-paste",
             description = _("Paste"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-redo",
             description = _("Redo"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-select-all",
             description = _("Select all"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "edit-undo",
             description = _("Undo"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "event-new",
             description = _("Create a new calendar event"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "folder-copy",
             description = _("Copy a folder"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "folder-move",
             description = _("Move a folder"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "folder-new",
             description = _("Create a new folder"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-indent-less",
             description = _("Decrease indent"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-indent-more",
             description = _("Increase indent"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-justify-center",
             description = _("Center justify text"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-justify-fill",
             description = _("Fill justify text"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-justify-left",
             description = _("Left justify text"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-justify-right",
             description = _("Right justify text"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-text-direction-ltr",
             description = _("Format text as left-to-right"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-text-direction-rtl",
             description = _("Format text as right-to-left"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-text-bold",
             description = _("Format text as bold"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-text-highlight",
             description = _("Format text as highlighted"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-text-italic",
             description = _("Format text as italic"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-text-underline",
             description = _("Format text as underlined"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "format-text-strikethrough",
             description = _("Format text as being struck through"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-bottom",
             description = _("Go to the bottom, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-down",
             description = _("Go down, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-first",
             description = _("Go to the first item, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-home",
             description = _("Go to the home location"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-jump",
             description = _("Jump to a location"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-last",
             description = _("Go to the last item, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-next",
             description = _("Go forward to the next item, such as in a list or navigation"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-previous",
             description = _("Go back to the previous item, such as in a list or navigation"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-top",
             description = _("Go to the top, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "go-up",
             description = _("Go up, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "help-about",
             description = _("Information about an app"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "help-contents",
             description = _("Get help"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "help-faq",
             description = _("Frequently asked questions"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "image-adjust",
             description = _("Make adjustments to an image"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "image-auto-adjust",
             description = _("Automatically adjust an image"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "image-crop",
             description = _("Crop an image"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "image-red-eye",
             description = _("Remove red eye from an image"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "insert-image",
             description = _("Insert an image"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "insert-link",
             description = _("Insert a link"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "insert-object",
             description = _("Insert an object"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "insert-text",
             description = _("Insert text"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "list-add",
             description = _("Add to a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "list-remove",
             description = _("Remove from a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-forward",
             description = _("Forward an email"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-mark-important",
             description = _("Mark an email as important"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-mark-junk",
             description = _("Mark an email as junk or spam"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-mark-notjunk",
             description = _("Mark an email as not junk or spam"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-mark-read",
             description = _("Mark an email as read"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-mark-unread",
             description = _("Mark an email as unread"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-message-new",
             description = _("Compose a new email"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-reply-all",
             description = _("Reply to all participants of an email"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-reply-sender",
             description = _("Reply to the sender of an email"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "mail-send",
             description = _("Send an email"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-eject",
             description = _("Eject removable media"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-playback-pause",
             description = _("Pause media playback"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-playback-start",
             description = _("Start playing media"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-playback-stop",
             description = _("Stop playing media"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-record",
             description = _("Start recording"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-seek-backward",
             description = _("Seek backwards or rewind"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-seek-forward",
             description = _("Seek forwards, or fastforward"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-skip-backward",
             description = _("Skip backwards, such as to the previous track"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "media-skip-forward",
             description = _("Skip forwards, such as to the next track"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "object-flip-horizontal",
             description = _("Flip an object horizontally"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "object-flip-vertical",
             description = _("Flip an object vertically"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "object-rotate-left",
             description = _("Rotate an object to the left or counter-clockwise"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "object-rotate-right",
             description = _("Rotate an object to the right or clockwise"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "process-stop",
             description = _("Stop an action that may take a while to process, such as web page loading in a browser"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "system-lock-screen",
             description = _("Lock the screen or the user's session"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "system-log-out",
             description = _("Log out of the user's session"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "system-run",
             description = _("Run a system app or command"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "system-search",
             description = _("Search the system"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "system-reboot",
             description = _("Restart the device"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "system-shutdown",
             description = _("Shut the device down"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "tools-check-spelling",
             description = _("Check spelling"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "view-fullscreen",
             description = _("View fullscreen"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "view-refresh",
             description = _("Refresh the current view"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "view-restore",
             description = _("Leave fullscreen and return to a normal window"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "view-sort-ascending",
             description = _("Sort items in an ascending order, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "view-sort-descending",
             description = _("Sort items in a descending order, such as in a list"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "window-close",
             description = _("Close the window"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "window-new",
             description = _("Create a new window"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "zoom-fit-best",
             description = _("Zoom to the best fit"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "zoom-in",
             description = _("Zoom in"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "zoom-original",
             description = _("Zoom to the original size"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "zoom-out",
             description = _("Zoom out"),
-            category = ACTIONS
+            category = Category.ACTIONS
         },
         Icon () {
             name = "accessories-calculator",
             description = _("Calculator"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "accessories-camera",
             description = _("Camera or webcam"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "accessories-character-map",
             description = _("International and extended text character map"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "accessories-dictionary",
             description = _("Dictionary"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "accessories-screenshot",
             description = _("Screenshot tool"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "accessories-text-editor",
             description = _("Text editor"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "application-default-icon",
             description = _("Default or unprovided app icon"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "archive-manager",
             description = _("Archive manager"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "internet-chat",
             description = _("Internet chat or messaging"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "internet-mail",
             description = _("Mail or email"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "internet-news-reader",
             description = _("News or feed reader"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "internet-web-browser",
             description = _("Web browser"),
-            category = APPS
+            category = Category.APPS
         },
 
         Icon () {
             name = "multimedia-audio-player",
             description = _("Music or audio player"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "multimedia-photo-manager",
             description = _("Photo manager or library"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "multimedia-video-player",
             description = _("Video or movie player"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "office-address-book",
             description = _("Address book or contacts"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "office-calendar",
             description = _("Calendar"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "postscript-viewer",
             description = _("Portable document or PDF viewer"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "preferences-desktop",
             description = _("System settings"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "system-file-manager",
             description = _("Files"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "system-os-installer",
             description = _("Install the operating system"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "system-software-install",
             description = _("AppCenter or software installer"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "system-software-update",
             description = _("Software updater"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "system-users",
             description = _("User settings"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "utilities-system-monitor",
             description = _("System resource monitor"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "utilities-terminal",
             description = _("Terminal"),
-            category = APPS
+            category = Category.APPS
         },
         Icon () {
             name = "applications-accessories",
             description = _("Accessory or utility app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-development",
             description = _("Programming, software development, code, or IDE app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-education",
             description = _("Education, learning, or school app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-engineering",
             description = _("Engineering app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-fonts",
             description = _("Font category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-games",
             description = _("Games app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-graphics",
             description = _("Graphics, drawing, art, or photo manipulation app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-internet",
             description = _("Internet or web related app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-multimedia",
             description = _("Multimedia, audio, or video app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-office",
             description = _("Office app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-other",
             description = _("Other or uncategorized app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-science",
             description = _("Science app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-system",
             description = _("System tools or OS app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "applications-utilities",
             description = _("Utility app category"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-bluetooth",
             description = _("Bluetooth settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-color",
             description = _("Color settings such as printer, display, or camera calibration"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop",
             description = _("Desktop interface settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-accessibility",
             description = _("Universal access settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-accessibility-pointing",
             description = _("Universal access settings for pointing, such as controlling the cursor"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-accessibility-zoom",
             description = _("Universal access settings for zooming or magnifying"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-applications",
             description = _("App-related settings, such as default or startup apps"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-display",
             description = _("Display settings, such as resolution or scaling"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-keyboard",
             description = _("Keyboard settings, such as layout or shortcuts"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-locale",
             description = _("International localization, language, or region settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-online-accounts",
             description = _("Online account and cloud sync or sign in settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-peripherals",
             description = _("Settings for peripherals, such as a mouse or keyboard"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-sound",
             description = _("Sound or audio input and output settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-desktop-wallpaper",
             description = _("Desktop wallpaper or background settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-other",
             description = _("Other, miscellaneous, or uncategorized settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system",
             description = _("System settings or preferences"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-network",
             description = _("Network settings, such as wireless, Ethernet, or VPN"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-notifications",
             description = _("Notification alert settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-parental-controls",
             description = _("Parental control settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-power",
             description = _("Power management or energy usage settings, such as battery"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-privacy",
             description = _("Privacy and security settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-sharing",
             description = _("Sharing settings, such as library sharing or media streaming over a network"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-time",
             description = _("Time and date settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "preferences-system-windows",
             description = _("Window management settings"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "system-help",
             description = _("Help"),
-            category = CATEGORIES
+            category = Category.CATEGORIES
         },
         Icon () {
             name = "audio-card",
             description = _("Audio output device, such as a sound card or speaker"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "audio-input-microphone",
             description = _("Microphone"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "audio-subwoofer",
             description = _("Subwoofer or bass speaker"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "battery",
             description = _("Battery"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "bluetooth",
             description = _("Bluetooth"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "camera-photo",
             description = _("Digital photo or still camera"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "camera-video",
             description = _("Video or movie camera"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "camera-web",
             description = _("Webcam or built-in camera"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "computer",
             description = _("Generic or desktop computer"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "computer-laptop",
             description = _("Laptop or notebook computer"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "drive-harddisk",
             description = _("Hard disk or storage drive"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "drive-optical",
             description = _("Optical drive, such as for CD, DVD, or Blu-ray discs"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "drive-removable-media",
             description = _("Removable storage device, such as a portable hard drive"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "drive-removable-media-usb",
             description = _("USB drive or stick, such as a flash, jump, or thumb drive"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "input-gaming",
             description = _("Video game controller, such as a paddle, remote, or joystick"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "input-keyboard",
             description = _("Keyboard"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "input-mouse",
             description = _("Mouse"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "input-tablet",
             description = _("Graphics tablet or pen input, such as a Wacom digitizer, Intuos, Cintiq, or Bamboo"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "input-touchpad",
             description = _("Touchpad input, such as a multitouch trackpad or clickpad"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "media-flash",
             description = _("Flash media such as a memory stick or SD card"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "media-optical",
             description = _("Optical media, such as a CD, DVD, or Blu-ray disc"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "modem",
             description = _("Network modem or router"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "multimedia-player",
             description = _("Media player device, such as a portable mp3 music player or iPod"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "network-cellular",
             description = _("Cellular type wireless network or device, such as a 2G, 3G, or 4G LTE connection, modem, or SIM card"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "network-firewall",
             description = _("Networking firewall"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "network-vpn",
             description = _("Virtual private network or VPN connection"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "network-wired",
             description = _("Wired network connection, such as Ethernet"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "network-wireless",
             description = _("Wireless network connection, such as Wi-Fi"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "network-wireless-hotspot",
             description = _("Wireless hotspot connection, such as through a mobile cellular phone or smartphone"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "phone",
             description = _("Generic phone, such as a mobile Android smartphone or iPhone"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "printer",
             description = _("Printer"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "printer-network",
             description = _("Network-connected or shared printer"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "scanner",
             description = _("Scanner"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "video-display",
             description = _("Display, screen, or monitor"),
-            category = DEVICES
+            category = Category.DEVICES
         },
         Icon () {
             name = "emblem-default",
             description = _("Default selection emblem, such as for a printer or other device"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-documents",
             description = _("Documents emblem"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-downloads",
             description = _("Downloads emblem"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-favorite",
             description = _("Item the user has marked as a favorite"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-important",
             description = _("Item marked as important"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-mail",
             description = _("Item related to email"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-photos",
             description = _("Photos emblem"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-readonly",
             description = _("Item is read-only, or the user cannot write to or make changes to it"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-shared",
             description = _("Item shared with other people or users"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-symbolic-link",
             description = _("Item is a symbolic link to a file somewhere else"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-synchronized",
             description = _("Item is configured to be synchronized to another device or location"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-system",
             description = _("Item is a system file, library, setting, or data"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "emblem-unreadable",
             description = _("Item is unreadable or inaccessible"),
-            category = EMBLEMS
+            category = Category.EMBLEMS
         },
         Icon () {
             name = "face-angel",
             description = _("0:-) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-angry",
             description = _("X-( emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-cool",
             description = _("B-) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-crying",
             description = _(":'( emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-devilish",
             description = _(">:-) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-embarrassed",
             description = _(":-[ emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-heart",
             description = _("<3 emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-heart-broken",
             description = _("</3 emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-kiss",
             description = _(":-* emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-laugh",
             description = _(":-)) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-monkey",
             description = _(":-(|) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-plain",
             description = _(":-| emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-raspberry",
             description = _(":-P emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-sad",
             description = _(":-( emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-sick",
             description = _(":-& emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-smile",
             description = _(":-) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-smile-big",
             description = _(":-D emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-smirk",
             description = _(":-! emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-surprise",
             description = _(":-0 emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-tired",
             description = _("|-) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-uncertain",
             description = _(":-/ emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-wink",
             description = _(";-) emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "face-worried",
             description = _(":-S emoticon"),
-            category = EMOTES
+            category = Category.EMOTES
         },
         Icon () {
             name = "application-epub+zip",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-illustrator",
             description = _("Adobe Illustrator image file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-javascript",
             description = _("Javascript programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-msword",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-octet-stream",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-pdf",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-pgp",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-vnd.debian.binary-package",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-vnd.ms-access",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-vnd.ms-excel",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-vnd.ms-powerpoint",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-vnd.oasis.opendocument.chart",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-bittorrent",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-cd-image",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-desktop",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-executable",
             description = _("Executable file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-fictionbook+xml",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-firmware",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-flash-video",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-php",
             description = _("PHP programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "application-x-ruby",
             description = _("Ruby programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "audio-x-generic",
             description = _("Generic audio file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "audio-x-playlist",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "extension",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "font-x-generic",
             description = _("Generic font file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "image-vnd.adobe.photoshop",
             description = _("Adobe Photoshop image file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "image-x-generic",
             description = _("Generic image file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "image-x-xcf",
             description = _("XCF image file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "internet-feed",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "model",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "office-contact",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "office-database",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "package-x-generic",
             description = _("Generic package file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-css",
             description = _("CSS text file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-html",
             description = _("HTML text file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-markdown",
             description = _("Markdown text file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-bibtex",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-changelog",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-chdr",
             description = _("C programming language header file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-copying",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-csrc",
             description = _("C programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-generic",
             description = _("Generic text file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-generic-template",
             description = _("Generic text templates"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-gettext-translation",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-gettext-translation-template",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-go",
             description = _("Go programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-install",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-makefile",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-preview",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-python",
             description = _("Python programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-readme",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-sass",
             description = _("Sass programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-script",
             description = _("Script file types, such as shell scripts"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-ssa",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-tex",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "text-x-vala",
             description = _("Vala programming language file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "unknown",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "video-x-generic",
             description = _("Generic video file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-address-book",
             description = _("Generic address book file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-calendar",
             description = _("Generic calendar file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-document",
             description = _("Generic document and letter file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-document-template",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-drawing",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-drawing-template",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-presentation",
             description = _("Generic presentation file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-presentation-template",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-spreadsheet",
             description = _("Generic spreadsheet file types"),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "x-office-spreadsheet-template",
             description = _(""),
-            category = MIMES
+            category = Category.MIMES
         },
         Icon () {
             name = "bookmark-missing",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "distributor-logo",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-documents",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-download",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-drag-accept",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-music",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-open",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-pictures",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-publicshare",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-recent",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-remote",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-saved-search",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-tag",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-templates",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "folder-videos",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "internet-radio",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "library-audiobook",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "library-places",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "library-podcast",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "mail-inbox",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "mail-mailbox",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "mail-outbox",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "mail-sent",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "network-server",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "network-workgroup",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "playlist",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "playlist-automatic",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "playlist-queue",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "playlist-similar",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "tag",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "user-bookmarks",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "user-home",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "user-trash",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "user-trash-full",
             description = _(""),
-            category = PLACES
+            category = Category.PLACES
         },
         Icon () {
             name = "airplane-mode",
             description = _("Airplane mode, where wireless radios are disabled or off"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "appointment-missed",
             description = _("An appointment or calendar event was missed"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "appointment-soon",
             description = _("An appointment or calendar event will be happening soon"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "audio-volume-high",
             description = _("High or loud audio volume"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "audio-volume-low",
             description = _("Low or quiet audio volume"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "audio-volume-medium",
             description = _("Medium or normal audio volume"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "audio-volume-muted",
             description = _("Audio volume is muted or off"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "audio-volume-muted-blocking",
             description = _("Audio volume is muted or off and something is being blocked from making noise"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "avatar-default",
             description = _("The default avatar to represent a user, such as someone who has not set a profile picture"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-ac-adapter",
             description = _("A charger or AC adapter for a battery-powered device"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-caution",
             description = _("Low battery level"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-caution-charging",
             description = _("Low battery level, plugged into a charger or AC adapter"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-empty",
             description = _("Critically low battery level"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-empty-charging",
             description = _("Critically low battery, plugged into a charger or AC adapter"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-full",
             description = _("Mostly charged battery level"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-full-charged",
             description = _("Completely charged battery level"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-full-charging",
             description = _("Mostly charged battery level, plugged into a charger or AC adapter"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-good",
             description = _("Medium-high charged battery level"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-good-charging",
             description = _("Medium-high charged battery level, plugged into a charger or AC adapter"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-low",
             description = _("Medium-low charged battery level"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-low-charging",
             description = _("Medium-low charged battery level, plugged into a charger or AC adapter"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "battery-missing",
             description = _("Missing or malfunctioning battery"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "bluetooth-disabled",
             description = _("Bluetooth radio is disabled or off"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "channel-insecure",
             description = _("Insecure, unsecure, or unencrypted communication or connection, such as HTTP"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "channel-secure",
             description = _("Secure or encrypted communication or connection, such as HTTPS or encrypted Wi-Fi"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "dialog-error",
             description = _("Critical, unrecoverable, or other serious error"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "dialog-information",
             description = _("Contextual information or explanation"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "dialog-password",
             description = _("Requesting authentication details, such as a password or encryption key"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "dialog-question",
             description = _("Question, decision, or choice for the user"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "dialog-warning",
             description = _("Warning of potentially dangerous actions or consequences"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "image-loading",
             description = _("Placeholder used when an image or thumbnail is loading"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "image-missing",
             description = _("Placeholder used when an image or thumbnail is missing or cannot be loaded"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "locked",
             description = _("Locked or secured, typically requiring authentication or a password to unlock"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "mail-attachment",
             description = _("Mail attachment or file in an email"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "mail-unread",
             description = _("New, unread, or unviewed email"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "mail-read",
             description = _("Read or already-viewed email"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "mail-replied",
             description = _("Email that has been replied or responded to"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "mail-signed",
             description = _("Email that contains a signature"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "mail-signed-verified",
             description = _("Email that contains a signature that is verified by the security system"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "media-playlist-repeat",
             description = _("Repeat a song, video, track, album, playlist, or other media"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "media-playlist-shuffle",
             description = _("Shuffle or randomize an album, playlist, or other media"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "network-error",
             description = _("Error or problem initializing or creating a network connection"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "network-idle",
             description = _("No data being transmitted or received while connected to a network"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "network-offline",
             description = _("Disconnected or offline from a network"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "network-receive",
             description = _("Data is being received over a network"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "network-transmit",
             description = _("Data is being transmitted over a network"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "network-transmit-receive",
             description = _("Data is being both transmitted and received simultaneously over a network"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "network-wired-disconnected",
             description = _("Wired network, such as Ethernet, is disconnected"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "non-starred",
             description = _("Item is not starred, favorited, or pinned by the user"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "notification-disabled",
             description = _("Notifications are disabled or in Do-Not-Disturb mode"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "printer-error",
             description = _("Error or problem occurred when attempting to print"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "printer-printing",
             description = _("Job has been successfully spooled or sent to a printer"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "process-completed",
             description = _("Process, job, or task has successfully completed or finished"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "security-high",
             description = _("Known to be secure, such as using strong encryption and a valid, verified, or trusted certificate"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "security-medium",
             description = _("Presumed to be secure, such as using encryption"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "security-low",
             description = _("Presumed to be insecure, such as unsecured, unencrypted, weak encryption, or an invalid, unverified, or untrusted certificate"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "software-update-available",
             description = _("Updated apps, software, or drivers are available"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "software-update-urgent",
             description = _("Urgent or critical updates are available"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "starred",
             description = _("Item is starred, favorited, or pinned by the user"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "task-due",
             description = _("Task is due soon"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "task-past-due",
             description = _("Task is incomplete past the due date"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "user-available",
             description = _("User, person, or contact is available or online"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "user-away",
             description = _("User, person, or contact is away or unavailable"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "user-idle",
             description = _("User, person, or contact is idle or unresponsive"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "user-offline",
             description = _("User, person, or contact is offline or unreachable"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "view-private",
             description = _("Private, anonymous, untracked, or incognito"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-clear",
             description = _("Clear skies or sunny weather"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-clear-night",
             description = _("Clear skies weather during the night"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-few-clouds",
             description = _("Partly cloudy, partly clear, or partly sunny weather"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-few-clouds-night",
             description = _("Partly cloudy or partly clear weather during the night"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-fog",
             description = _("Foggy weather"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-overcast",
             description = _("Overcast or cloudy weather"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-severe-alert",
             description = _("Severe or critical weather warning or alert"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-showers",
             description = _("Showers or rainy weather"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-showers-scattered",
             description = _("Scattered showers or partly rainy weather"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-snow",
             description = _("Snow showers or snowy weather"),
-            category = STATUS
+            category = Category.STATUS
         },
         Icon () {
             name = "weather-storm",
             description = _("Thunderstorms or stormy weather"),
-            category = STATUS
+            category = Category.STATUS
         }
     };
 
