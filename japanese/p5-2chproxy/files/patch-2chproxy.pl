--- 2chproxy.pl.orig	2016-11-16 00:35:06 UTC
+++ 2chproxy.pl
@@ -90,8 +90,8 @@ my $PROXY_CONFIG  = {
   HANDLED_COOKIES => [qw(__cfduid yuki PREN)],        #KEEP_COOKIEが有効な時にプロクシで保持するクッキー
   DAT_URL => '^http://([\w]+)(\.2ch\.net|\.bbspink\.com)(:[\d]+)?/([\w]+)/(?:dat|kako/\d+(?:/\d+)?)/([\d]+(?:-[\d]+)?)\.dat(\.gz)?$',  #datへのアクセスかを判定する正規表現
   NULL_DEVICE => '/dev/null',                         #nullデバイスの場所
-  PID_FILE_NAME => "/tmp/2chproxy.pid",               #pidが書かれたファイル、2重起動禁止にも用いている
-  LOG_FILE_NAME => "/tmp/2chproxy.log",               #ログファイル
+  PID_FILE_NAME => "/var/run/2chproxy.pid",               #pidが書かれたファイル、2重起動禁止にも用いている
+  LOG_FILE_NAME => "/var/log/2chproxy.log",               #ログファイル
   NULL_DEVICE_WIN32 => 'nul',                         #nullデバイスの場所(Windows)
   PID_FILE_NAME_WIN32 => dirname($0)."/2chproxy.pid", #pidが書かれたファイル、2重起動禁止にも用いている(Windows)
   LOG_FILE_NAME_WIN32 => dirname($0)."/2chproxy.log", #ログファイル(Windows)
@@ -325,11 +325,12 @@ sub daemonize() {
   fork() and exit(0);
   POSIX::setsid();
   fork() and exit(0);
-  umask(0);
+  umask(022);
   chdir('/');
   open(STDIN, '<', $null_device_name) or die;
   open(STDOUT, '>', $log_file_name) or die;
   open(STDERR, '>', $log_file_name) or die;
+  chmod(0600, $log_file_name) or die;
 
   return 0;
 }
