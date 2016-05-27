#############################################################################
To enable hv_kvp, you should do the steps following:
   # Deleting kvp label
   sed -i "" '/Loader labels for Hyper-V KVP drivers/d' /etc/rc.conf
   sed -i "" '/hv_kvp_load/d' /etc/rc.conf

   #hyperv driver names
   echo  '# Loader labels for Hyper-V KVP drivers -do not modify' >> /boot/loader.conf
   echo  'hv_kvp_load="YES"' >> /boot/loader.conf

# KVP - daemon label
   sed -i "" '/Label for KVP daemon/d' /etc/rc.conf
   sed -i "" '/hv_kvp_daemon_enable/d' /etc/rc.conf
   echo  '# Label for KVP daemon -do not modify' >> /etc/rc.conf
   echo  'hv_kvp_daemon_enable="YES"' >> /etc/rc.conf
After deinstall, you should restore /boot/loader.conf and /etc/rc.conf
#############################################################################
