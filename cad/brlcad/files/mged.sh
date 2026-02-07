#!/bin/sh
# This is pretty lame for the time being, but it serves as a reminder
# to set correctly your environment before attempting to run BRL CAD.

BRLCAD_ROOT=%%BRLCAD_ROOT%%

export BRLCAD_ROOT
export PATH=%%BRLCAD_ROOT%%/bin:$PATH
export MANPATH=%%BRLCAD_ROOT%%/man:$MANPATH
export ITCL_PATH=%%BRLCAD_ROOT%%/lib/itcl3.4
export ITK_PATH=%%BRLCAD_ROOT%%/lib/itk3.4

exec %%BRLCAD_ROOT%%/bin/mged "$@"
