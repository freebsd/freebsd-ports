#!/bin/sh
#
# $FreeBSD$
#

QSERVER=%%PREFIX%%/quakeserver/unixded
QPIPE=%%PREFIX%%/quakeserver/quakeserver.in
LOG=%%PREFIX%%/quakeserver/quakeserver.log

cd %%PREFIX%%/quakeserver

# This runs the standard quakeserver game, suitable for LAN play
QARGS=	

# A few other ideas/options:

# To run a game better suited for modem play:
#QARGS=	+sys_ticrate 0.1

# To run a registered game (assuming that you've put the registered *.pak
# files into %%PREFIX%%/quakeserver/reg/
#QARGS=	-game reg

# To force the server to bind to just one IP address (to run multiple
# servers on the same machine)
#QARGS=	-ip x.x.x.x

# For more ideas, look at %%PREFIX%%/quakeserver/readme.unixded as well as
# the documentation that comes with Quake.

# This actually runs the server
$QSERVER $QARGS < $QPIPE >> $LOG &

# Put commands you want to stuff into the console here, each being
# redirected into %%PREFIX%%/quakeserver/quakeserver.in
echo "map e1m1" > $QPIPE

#
# EOF
