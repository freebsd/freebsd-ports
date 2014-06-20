import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.Icon;
import java.awt.EventQueue;

public class Notifer extends JFrame{
    
    //Using a standard Java icon
    private Icon optionIcon = UIManager.getIcon("FileView.computerIcon");
    
    public static void main(String[] args) {
     
     EventQueue.invokeLater(new Runnable()
     {
         public void run()
         {
             //create GUI frame
             new Notifer().setVisible(true);          
         }
     });
              
    }
    
    public Notifer()
    {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //setTitle("Simple Dialog Box Example");
        //setSize(500,500);
        
        setLocationRelativeTo(null); 
        
        // Show our warning to first time users
        JOptionPane.showMessageDialog(this, "After the first time logging in with a new user, you will need to close the Minecraft Launcher and restart before the game will run." 
                ,"Important Notification", JOptionPane.PLAIN_MESSAGE);

	System.exit(0);
        
    }
}
