#!/bin/sh

. $MACRO_DIR/makegen/makegen.cf

obj=$1
src=$2
shift; shift
deps=$*

base=`echo $src | sed "s/\..*//"`

echo
echo	"# Make rules for building $obj"
echo
echo	"$obj : $src Makefile.full $deps"
echo	'	$(CC) $(CC_FLAGS) -fpic -DPIC -o '$obj' -c $(SOURCE_DIR)'/$src
echo
echo	"clean ::"
echo	"	rm -f $obj $base.lint"
echo
