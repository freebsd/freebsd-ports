#!/bin/sh
#
# Wrapper script of han.
#
# 12 Apr 1997, Choi Jun Ho <junker@jazz.snu.ac.kr>
#
gzip -cd %%PREFIX%%/share/fonts/han/h16m.bdf.gz \
	| %%PREFIX%%/bin/hanfld -t bdf -n
gzip -cd %%PREFIX%%/share/fonts/han/8x16pc.bdf.gz \
	| %%PREFIX%%/bin/hanfld -t bdf -n
exec han.bin
