#!/bin/sh

LANG=%%LOCALENAME%%; export LANG
#XMODIFIERS=@im=xcin; export XMODIFIERS
#LD_PRELOAD=%%LOCALBASE%%/lib/libflashplayer.so.1; export LD_PRELOAD

FIREFOX_DIR="%%PREFIX%%/lib/%%FIREFOX%%"
FIREFOX_EXEC="firefox-bin"
LOCATION='new-tab'

cd $FIREFOX_DIR                                     || exit 1

case $1 in
    -mail)
    	REMOTE_COMMAND="xfeDoCommand (openInbox)"
	;;
    -*)
    	exec ./$FIREFOX_EXEC "$@"
	;;
    *)
    	REMOTE_COMMAND="openURL($@, $LOCATION)"
	;;
esac
    
# process found
./$FIREFOX_EXEC -remote "ping()"                    &&
./$FIREFOX_EXEC -remote "$REMOTE_COMMAND"           && exit 0

# no existing process
exec ./$FIREFOX_EXEC "$@"

