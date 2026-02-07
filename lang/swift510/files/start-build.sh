swift_project_dir=$1
swift_install_destdir=$2
swift_install_prefix=$3
clang_module_cache_path=$4

# For tools like 'ld', 'ar', 'ranlib', etc. prefer the versions from the base system
export PATH="/sbin:/bin:/usr/sbin:/usr/bin:${PATH}"

export CLANG_MODULE_CACHE_PATH=${clang_module_cache_path}

if [ ${CCACHE_ENABLED} = yes ] ; then
	ccache_fragment="--cmake-c-launcher ${CCACHE_BIN} --cmake-cxx-launcher ${CCACHE_BIN}"
else
	ccache_fragment=
fi

if [ -n "${MAKE_JOBS_NUMBER}" ] ; then
	jobs_fragment="--jobs ${MAKE_JOBS_NUMBER}"
else
	jobs_fragment=
fi

cd ${swift_project_dir}/swift &&
utils/build-script --bootstrapping bootstrapping \
--release \
--assertions \
--host-cc /usr/bin/clang \
--host-cxx /usr/bin/clang++ \
${ccache_fragment} \
${jobs_fragment} \
--llvm-targets-to-build 'AArch64;X86' \
--skip-early-swift-driver \
--skip-early-swiftsyntax \
--libdispatch true \
--foundation true \
--xctest true \
--swiftpm true \
--llbuild true \
--swiftsyntax true \
--swift-driver true \
--extra-cmake-options="-DSWIFT_USE_LINKER=lld" \
--extra-cmake-options="-DLLVM_USE_LINKER=lld" \
--llvm-max-parallel-lto-link-jobs 1 \
--swift-tools-max-parallel-lto-link-jobs 1 \
--install-destdir ${swift_install_destdir} \
--install-prefix ${swift_install_prefix} \
--install-all true \
--verbose-build true
