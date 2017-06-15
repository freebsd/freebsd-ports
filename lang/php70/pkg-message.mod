*********************************************************************

Make sure index.php is part of your DirectoryIndex.

You should add the following to your Apache configuration file:

<FilesMatch "\.php$">
    SetHandler application/x-httpd-php
</FilesMatch>
<FilesMatch "\.phps$">
    SetHandler application/x-httpd-php-source
</FilesMatch>

*********************************************************************

If you are building PHP-based ports in poudriere(8) with ZTS enabled,
add WITH_MPM=event to /etc/make.conf to prevent build failures.

*********************************************************************
