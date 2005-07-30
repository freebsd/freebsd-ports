#!/bin/sh
#
# $FreeBSD$
#

cd %%DATADIR%%
exec %%JAVAVM%% \
    -classpath $(%%CLASSPATH%%) \
    com.bbn.openmap.app.OpenMap "%@"
