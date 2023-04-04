#!/bin/sh

# Script removes module definition blocks in LLVM/Clang .modulemap
# files "in-place" in the file path stored in the variable MODULEMAP

modules=$1
tmp=${MODULEMAP}.tmp && awk -f ${SCRIPTDIR}/remove-modules-from-modulemap.awk -v exclude="${modules}" ${MODULEMAP} > ${tmp} && mv ${tmp} ${MODULEMAP} || rm ${tmp}
