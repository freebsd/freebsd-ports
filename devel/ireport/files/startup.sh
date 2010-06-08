#! /bin/sh
#set -x

IREPORT_HOME="$HOME/.ireport/%%PORTVERSION%%"

java -Djdk.home=%%JAVA_HOME%% -classpath "%%DATADIR%%/platform9/lib/boot.jar:%%DATADIR%%/platform9/lib/org-openide-modules.jar:%%DATADIR%%/platform9/lib/org-openide-util.jar:%%CLSSPTH%%" -Dnetbeans.system_http_proxy=DIRECT -Dnetbeans.system_http_non_proxy_hosts= -Dnetbeans.dirs="%%DATADIR%%/ireport:%%DATADIR%%/ide10:%%DATADIR%%/nb6.5:" -Dnetbeans.home="%%DATADIR%%/platform9" -Xms256m -Xmx512m -Dorg.netbeans.ProxyClassLoader.level=1000 org.netbeans.Main --userdir $IREPORT_HOME --branding ireport "$@"
