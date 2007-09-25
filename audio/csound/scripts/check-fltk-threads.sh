#!/bin/sh

if [ -x ${FLTKBASE}/bin/fltk-config ] && [ -z "$(fltk-config --ldflags | grep pthread)" ]; then
	echo "FLTK does not have threading support enabled."
	echo "Please remove the x11-toolkits/fltk port first and recompile csound again"
	echo "The csound port will automatically install the x11-toolkits/fltk-threads port."
	exit 1
else
	exit 0
fi
