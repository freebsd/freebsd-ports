%%APACHEMODDIR%%/%%AP_MODULE%%
@exec %D/sbin/apxs -e -a -n %%AP_NAME%% %f
@unexec %D/sbin/apxs -e -A -n %%AP_NAME%% %f
