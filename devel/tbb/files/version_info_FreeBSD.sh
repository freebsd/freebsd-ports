#!/bin/sh

# Script used to generate version info string
echo "#define __TBB_VERSION_STRINGS \\"
echo '"TBB:' "BUILD_HOST\t\t"`hostname -s`" ("`uname -p`")"'" ENDL \'
echo '"TBB:' "BUILD_OS\t\t"`uname -sr`'" ENDL \'
echo '"TBB:' "BUILD_KERNEL\t"`uname -rv`'" ENDL \'
echo '"TBB:' "BUILD_GCC\t\t"`g++ -v </dev/null 2>&1 | grep 'gcc.*version'`'" ENDL \'
[ -z "$COMPILER_VERSION" ] || echo '"TBB:' "BUILD_COMPILER\t"$COMPILER_VERSION'" ENDL \'
echo '"TBB:' "BUILD_GLIBC\t"`ldconfig -r | grep -oE '/lib/libc.so.[0-9]+' | sort -rn | head -n 1 | sed 's|/lib/libc\.so\.||'`'" ENDL \'
echo '"TBB:' "BUILD_LD\t\t"`ld -v | grep 'version'`'" ENDL \'
echo '"TBB:' "BUILD_TARGET\t$arch on $runtime"'" ENDL \'
echo '"TBB:' "BUILD_COMMAND\t"$*'" ENDL \'
echo ""
echo "#define __TBB_DATETIME \""`date -u`"\""
