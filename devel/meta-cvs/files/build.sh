#!/bin/sh
#
# $FreeBSD$

CLISP_LIB=$(clisp -q -norc -x '(progn (princ *lib-directory*) (values))')

LINKSET=unix-bindings-linking-set

if [ ! -e $LINKSET ] ; then
    export CLISP_LINKKIT="${CLISP_LIB}linkkit"
    sh "${CLISP_LIB}clisp-link" add-module-set unix-bindings \
    "${CLISP_LIB}base" $LINKSET
fi

LISPRUN=$LINKSET/lisp.run

if ! $LISPRUN -M $LINKSET/lispinit.mem -q -c mcvs-main ; then
  echo "There were compilation errors."
  exit 1
fi

$LISPRUN -M $LINKSET/lispinit.mem -q -i mcvs-main -x '(ext:saveinitmem "mcvs.mem" :quiet t)'

exit 0
