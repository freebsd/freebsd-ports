#!/bin/sh

# Script used to generate FreeBSD version info string
echo "#define __TBB_VERSION_STRINGS(N) \\"
echo '#N": BUILD_HOST'"\t\t"`hostname -s`" ("`uname -m`")"'" ENDL \'
echo '#N": BUILD_OS'"\t\t"`uname -sr`'" ENDL \'
echo '#N": BUILD_KERNEL'"\t"`uname -i`'" ENDL \'
echo '#N": BUILD_GCC'"\t\t"`${CXX} --version </dev/null 2>&1 | head -n 1`'" ENDL \'
[ -z "$COMPILER_VERSION" ] || echo '#N": BUILD_COMPILER'"\t"$COMPILER_VERSION'" ENDL \'
echo '#N": BUILD_GLIBC'"\t"`ldconfig -r | grep -oE '/lib/libc.so.[0-9]+' | sort -rn | head -n 1 | sed 's|/lib/libc\.so\.||'`'" ENDL \'
echo '#N": BUILD_LD'"\t\t"`ld -v 2>&1 | head -n 1`'" ENDL \'
echo '#N": BUILD_TARGET'"\t$arch on $runtime"'" ENDL \'
echo '#N": BUILD_COMMAND'"\t"$*'" ENDL \'
echo ""
echo "#define __TBB_DATETIME \""`date -u`"\""
