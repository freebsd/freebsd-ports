#!/bin/sh

DIR=%%PREFIX%%/games/atitd
CLIENT=elaunch
XHOST=/usr/X11R6/bin/xhost

$XHOST +nis:atitd@
cd ${DIR}
./${CLIENT} -nosound $*
$XHOST -nis:atitd@
