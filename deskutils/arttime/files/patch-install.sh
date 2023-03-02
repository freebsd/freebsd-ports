--- install.sh.orig	2023-02-25 08:04:14 UTC
+++ install.sh
@@ -276,30 +276,5 @@ elif [[ $machine =~ ^Darwin.*$ ]]; then
     echo "[4mNote[0m: Notification settings on macOS are not fully in control of an application.\n      To check if you have desired notification settings, open following link.\n      https://github.com/poetaman/arttime/issues/11"
 fi
 
-# Check if path to arttime excutable is on user's $PATH
-if [[ ":$PATH:" == *":$bindir:"* ]]; then
-    echo "Installation complete!\nType 'arttime' and press Enter to start arttime."
-else
-    loginshell=$(basename "${SHELL}")
-    if [[ $loginshell == *zsh* ]]; then
-        profile='.zshrc'
-    elif [[ $loginshell == *bash* ]]; then
-        #if [[ -e $HOME/.bash_profile ]]; then
-        #    profile='.bash_profile'
-        #else
-        #    profile='.profile'
-        #fi
-        profile=".bashrc"
-    else
-        profile=''
-    fi
-    if [[ ! -z $profile ]]; then
-        echo "\n# Following line was automatically added by arttime installer" >>$HOME/$profile
-        echo 'export PATH='"$bindir"':$PATH' >>$HOME/$profile
-        echo 'Note: Added export PATH='"$bindir"':$PATH to ~/'"$profile"
-        echo "Installation complete!\nSource ~/$profile or restart terminal. Then type 'arttime' and press Enter to start arttime."
-    else
-        echo "Installation [31m*[0malmost[31m*[0m complete! To start using arttime, follow these steps:\n    1) Add $bindir to your PATH environment variable in appropriate file,\n    2) Open a new terminal session, type 'arttime' and press Enter.\nTo run it right away from this shell, execute arttime by specifying its full path:\n       $bindir/arttime"
-    fi
-fi
 echoti cnorm
+exit 0
