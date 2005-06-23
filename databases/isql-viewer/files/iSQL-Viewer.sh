#!/bin/sh

JAVA_VERSION=%%JAVA_VERSION%% \
	java -classpath %%CLASSPATH%% \
	     org.isqlviewer.core.Launcher
