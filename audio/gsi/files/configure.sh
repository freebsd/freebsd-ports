#!/bin/sh

PREFIX=$1
SYSCONFSCRIPT=Config/Configure_system.sh
APPCONFSCRIPT=Config/Configure_application.sh

# Change to the work directory.
cd $2

# Execute two configure scripts while piping the output to /dev/null.
# This is because the output looks somewhat mashed.
echo -n "Executing ${SYSCONFSCRIPT}... "
${SYSCONFSCRIPT} << _E_O_M_ > /dev/null 2>&1
0
${PREFIX}
_E_O_M_
echo "done."

echo -n "Executing ${APPCONFSCRIPT}... "
${APPCONFSCRIPT} << _E_O_M2_ > /dev/null 2>&1
3




_E_O_M2_
echo "done."
