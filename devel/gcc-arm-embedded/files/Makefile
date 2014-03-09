# $FreeBSD$

.include "Makefile.inc"

MULTILIB_LIST=	armv6-m,armv7-m,armv7e-m,armv7-r
PKGVERSION=	GNU Tools for ARM Embedded Processors

BUILD_PREFIX=	${WRKDIR}/build
DOC_PREFIX=	${INTERIM_PREFIX}/${DOCS_SUFFIX}

LDFLAGS+=	-L${LOCALBASE}/lib

.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error
CXXFLAGS+=	-Wno-error
.endif

MISC_DOCS=	license.txt readme.txt release.txt

ALL_BUILD=	build-binutils \
		build-gcc-first \
		build-newlib \
		build-newlib-nano \
		build-gcc-final \
		build-gcc-plugins \
		build-libstdcxx \
		build-gdb  \
		install-samples \
		install-misc \
		strip-binaries \
		strip-target-libraries

.PHONY: ${ALL_BUILD}

all: ${ALL_BUILD}

build-binutils:
	@${ECHO_MSG} "====>  Build binutils (log file: ${WRKDIR}/binutils.log)"
	@${RM} -rf ${BUILD_PREFIX}/binutils > ${WRKDIR}/binutils.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/binutils >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/binutils && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/binutils/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --disable-nls \
	 --enable-plugins \
	 --with-sysroot=${INTERIM_PREFIX}/${TARGET} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/binutils all >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/binutils install >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Prepare working area for library builds"
	@${MKDIR} ${BUILD_PREFIX}/target-libs >> ${WRKDIR}/binutils.log 2>&1
	@${TAR} -cf - -C ${INTERIM_PREFIX} . | ${TAR} -xf - -C ${BUILD_PREFIX}/target-libs >> ${WRKDIR}/binutils.log 2>&1
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/binutils html >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/binutils install-html >> ${WRKDIR}/binutils.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/binutils pdf >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/binutils install-pdf >> ${WRKDIR}/binutils.log 2>&1
.endif
	@${ECHO_MSG} "=====>  Cleanup installation"
	@${RM} -rf ${INTERIM_PREFIX}/lib >> ${WRKDIR}/binutils.log 2>&1

build-gcc-first:
	@${ECHO_MSG} "====>  Build preliminary gcc (log file: ${WRKDIR}/gcc-first.log)"
	@${RM} -rf ${BUILD_PREFIX}/gcc-first > ${WRKDIR}/gcc-first.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gcc-first >> ${WRKDIR}/gcc-first.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gcc-first && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gcc/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --libexecdir=${INTERIM_PREFIX}/lib \
	 --with-gmp=${LOCALBASE} \
	 --with-mpfr=${LOCALBASE} \
	 --with-mpc=${LOCALBASE} \
	 --with-isl=${LOCALBASE} \
	 --disable-isl-version-check \
	 --with-cloog=${LOCALBASE} \
	 --with-libelf=${LOCALBASE} \
	 --enable-languages=c \
	 --disable-decimal-float \
	 --disable-libffi \
	 --disable-libgomp \
	 --disable-libmudflap \
	 --disable-libquadmath \
	 --disable-libssp \
	 --disable-libstdcxx-pch \
	 --disable-nls \
	 --disable-shared \
	 --disable-threads \
	 --disable-tls \
	 --with-newlib \
	 --without-headers \
	 --with-gnu-as \
	 --with-gnu-ld \
	 --with-python-dir=share/gcc-${TARGET} \
	 --with-sysroot=${INTERIM_PREFIX}/${TARGET} \
	 --with-multilib-list=${MULTILIB_LIST} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/gcc-first.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gcc-first all >> ${WRKDIR}/gcc-first.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gcc-first install-gcc >> ${WRKDIR}/gcc-first.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/bin/${TARGET}-gccbug >> ${WRKDIR}/gcc-first.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/lib/libiberty.a >> ${WRKDIR}/gcc-first.log 2>&1
	@${RM} -rf ${INTERIM_PREFIX}/include >> ${WRKDIR}/gcc-first.log 2>&1

build-newlib:
	@${ECHO_MSG} "====>  Build newlib (log file: ${WRKDIR}/newlib.log)"
	@${RM} -rf ${BUILD_PREFIX}/newlib > ${WRKDIR}/newlib.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/newlib >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/newlib && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" CFLAGS_FOR_TARGET="-g -O2 -fno-unroll-loops -ffunction-sections -fdata-sections" \
	  ${SRC_DIR}/newlib/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --enable-newlib-io-long-long \
	 --enable-newlib-register-fini \
	 --disable-newlib-supplied-syscalls \
	 --disable-nls >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${GMAKE} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/newlib all >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${GMAKE} -C ${BUILD_PREFIX}/newlib install >> ${WRKDIR}/newlib.log 2>&1
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/newlib html >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MKDIR} ${DOC_PREFIX}/html/libc >> ${WRKDIR}/newlib.log 2>&1
	@${TAR} -cf - -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libc/libc.html . | ${TAR} -xf - -C ${DOC_PREFIX}/html/libc >> ${WRKDIR}/newlib.log 2>&1
	@${MKDIR} ${DOC_PREFIX}/html/libm >> ${WRKDIR}/newlib.log 2>&1
	@${TAR} -cf - -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libm/libm.html . | ${TAR} -xf - -C ${DOC_PREFIX}/html/libm >> ${WRKDIR}/newlib.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation (ignore errors)"
	@-${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libc pdf >> ${WRKDIR}/newlib.log 2>&1
	@-${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libm pdf >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${CP} -f ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libc/libc.pdf ${DOC_PREFIX}/pdf/libc.pdf >> ${WRKDIR}/newlib.log 2>&1
	@${CP} -f ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libm/libm.pdf ${DOC_PREFIX}/pdf/libm.pdf >> ${WRKDIR}/newlib.log 2>&1
.endif

build-newlib-nano:
	@${ECHO_MSG} "====>  Build newlib-nano (log file: ${WRKDIR}/newlib-nano.log)"
	@${RM} -rf ${BUILD_PREFIX}/newlib-nano > ${WRKDIR}/newlib-nano.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/newlib-nano >> ${WRKDIR}/newlib-nano.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/newlib-nano && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" CFLAGS_FOR_TARGET="-g -Os -ffunction-sections -fdata-sections" \
	  ${SRC_DIR}/newlib-nano-2.0/configure \
	 --target=${TARGET} \
	 --prefix=${BUILD_PREFIX}/target-libs \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --disable-newlib-supplied-syscalls    \
	 --enable-newlib-reent-small           \
	 --disable-newlib-fvwrite-in-streamio  \
	 --disable-newlib-fseek-optimization   \
	 --disable-newlib-wide-orient          \
	 --enable-newlib-nano-malloc           \
	 --disable-newlib-unbuf-stream-opt     \
	 --enable-lite-exit                    \
	 --enable-newlib-global-atexit         \
	 --disable-nls >> ${WRKDIR}/newlib-nano.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${GMAKE} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/newlib-nano all >> ${WRKDIR}/newlib-nano.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${GMAKE} -C ${BUILD_PREFIX}/newlib-nano install  >> ${WRKDIR}/newlib-nano.log 2>&1

build-gcc-final:
	@${ECHO_MSG} "====>  Build final gcc and g++ (log file: ${WRKDIR}/gcc-final.log)"
	@${RM} -f ${INTERIM_PREFIX}/${TARGET}/usr > ${WRKDIR}/gcc-final.log 2>&1
	@${LN} -s . ${INTERIM_PREFIX}/${TARGET}/usr >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -rf ${BUILD_PREFIX}/gcc-final >> ${WRKDIR}/gcc-final.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gcc-final >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gcc-final && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gcc/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --libexecdir=${INTERIM_PREFIX}/lib \
	 --with-gmp=${LOCALBASE} \
	 --with-mpfr=${LOCALBASE} \
	 --with-mpc=${LOCALBASE} \
	 --with-isl=${LOCALBASE} \
	 --disable-isl-version-check \
	 --with-cloog=${LOCALBASE} \
	 --with-libelf=${LOCALBASE} \
	 --enable-languages=c,c++ \
	 --enable-plugins \
	 --disable-decimal-float \
	 --disable-libffi \
	 --disable-libgomp \
	 --disable-libmudflap \
	 --disable-libquadmath \
	 --disable-libssp \
	 --disable-libstdcxx-pch \
	 --disable-nls \
	 --disable-shared \
	 --disable-threads \
	 --disable-tls \
	 --with-gnu-as \
	 --with-gnu-ld \
	 --with-newlib \
	 --with-headers=yes \
	 --with-python-dir=share/gcc-${TARGET} \
	 --with-sysroot=${INTERIM_PREFIX}/${TARGET} \
	 --with-multilib-list=${MULTILIB_LIST} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gcc-final INHIBIT_LIBC_CFLAGS="-DUSE_TM_CLONE_REGISTRY=0" all >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gcc-final install >> ${WRKDIR}/gcc-final.log 2>&1
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gcc-final html >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gcc-final install-html >> ${WRKDIR}/gcc-final.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gcc-final pdf >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gcc-final install-pdf >> ${WRKDIR}/gcc-final.log 2>&1
.endif
	@${ECHO_MSG} "=====>  Cleanup installation"
	@${RM} -f ${INTERIM_PREFIX}/bin/${TARGET}-gccbug >> ${WRKDIR}/gcc-final.log 2>&1
	@${FIND} ${INTERIM_PREFIX}/${TARGET}/lib -name libiberty.a -delete >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/lib/libiberty.a >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -rf ${INTERIM_PREFIX}/include >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/${TARGET}/usr >> ${WRKDIR}/gcc-final.log 2>&1

build-gcc-plugins:
	@${ECHO_MSG} "====>  Build gcc plugins (log file: ${WRKDIR}/gcc-plugins.log)"
	@${RM} -f ${WRKDIR}/gcc-plugins.log
	@plugin_target_dir=$$(${INTERIM_PREFIX}/bin/${TARGET}-gcc -print-file-name=plugin) && \
	 plugins=$$(${FIND} ${SRC_DIR}/gcc-plugins -mindepth 1 -maxdepth 1 -type d -name '[^\.]*') && \
	 for plugin_dir in $${plugins} ; do \
	   plugin_name=$$(basename "$${plugin_dir}") && \
	   src_files=$$(${FIND} $${plugin_dir} -name \*.c -or -name \*.cc) && \
	   ${ECHO_MSG} "=====>  Build plugin $${plugin_name} from $${src_files}" && \
	   ${ECHO_MSG} "Build plugin $${plugin_name} from $${src_files}" >> ${WRKDIR}/gcc-plugins.log && \
	   ${CXX} ${CXXFLAGS} ${CPPFLAGS} -fPIC -fno-rtti -O2 -shared -I$${plugin_target_dir}/include -I${LOCALBASE}/include $${src_files} \
	    -o $${plugin_target_dir}/$${plugin_name}.so >> ${WRKDIR}/gcc-plugins.log 2>&1 ; \
	 done

build-libstdcxx:
	@${ECHO_MSG} "====>  Build size-optimized C++ runtime (log file: ${WRKDIR}/gcc-size-libstdcxx.log)"
	@${RM} -f ${BUILD_PREFIX}/target-libs/${TARGET}/usr > ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${LN} -s . ${BUILD_PREFIX}/target-libs/${TARGET}/usr >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${RM} -rf ${BUILD_PREFIX}/gcc-size-libstdcxx >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gcc-size-libstdcxx >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gcc-size-libstdcxx && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gcc/configure \
	 --target=${TARGET} \
	 --prefix=${BUILD_PREFIX}/target-libs \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --with-gmp=${LOCALBASE} \
	 --with-mpfr=${LOCALBASE} \
	 --with-mpc=${LOCALBASE} \
	 --with-isl=${LOCALBASE} \
	 --disable-isl-version-check \
	 --with-cloog=${LOCALBASE} \
	 --with-libelf=${LOCALBASE} \
	 --enable-languages=c,c++ \
	 --disable-decimal-float \
	 --disable-libffi \
	 --disable-libgomp \
	 --disable-libmudflap \
	 --disable-libquadmath \
	 --disable-libssp \
	 --disable-libstdcxx-pch \
	 --disable-nls \
	 --disable-shared \
	 --disable-threads \
	 --disable-tls \
	 --with-gnu-as \
	 --with-gnu-ld \
	 --with-newlib \
	 --with-headers=yes \
	 --with-python-dir=share/gcc-${TARGET} \
	 --with-sysroot=${BUILD_PREFIX}/target-libs/${TARGET} \
	 --with-multilib-list=${MULTILIB_LIST} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gcc-size-libstdcxx \
	 CXXFLAGS_FOR_TARGET="-g -Os -ffunction-sections -fdata-sections -fno-exceptions" all >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gcc-size-libstdcxx install >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Copy all target libraries into stage directory"
	@for multilib in $$(${BUILD_PREFIX}/target-libs/bin/${TARGET}-gcc -print-multi-lib) ; do \
	  multilib_dir=$${multilib%%;*} ; \
	  for srclib in libstdc++.a libsupc++.a libc.a libg.a librdimon.a nano.specs rdimon.specs nosys.specs ; do \
	    dstlib=$$(echo "$${srclib}" | ${SED} 's/\.a$$/_s.a/') ; \
	    ${CP} -f ${BUILD_PREFIX}/target-libs/${TARGET}/lib/$${multilib_dir}/$${srclib} ${INTERIM_PREFIX}/${TARGET}/lib/$${multilib_dir}/$${dstlib} ; \
	  done ; \
	  ${CP} -f ${BUILD_PREFIX}/target-libs/${TARGET}/lib/$${multilib_dir}/*crt0.o  ${INTERIM_PREFIX}/${TARGET}/lib/$${multilib_dir}/ ; \
	 done >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1

build-gdb:
	@${ECHO_MSG} "====>  Build gdb (log file: ${WRKDIR}/gdb.log)"
	@${RM} -rf ${BUILD_PREFIX}/gdb > ${WRKDIR}/gdb.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gdb >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gdb && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gdb/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --disable-nls \
	 --disable-sim \
	 --with-libexpat \
	 --with-libexpat-prefix=${LOCALBASE} \
	 --with-python=no \
	 --with-system-gdbinit=${INTERIM_PREFIX}/xxxx/${TARGET}/lib/gdbinit \
	 --with-gdb-datadir='$${prefix}/${TARGET}/share/gdb' \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gdb all >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gdb install >> ${WRKDIR}/gdb.log 2>&1
	@${RM} -rf ${INTERIM_PREFIX}/include
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gdb html >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gdb install-html >> ${WRKDIR}/gdb.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gdb pdf >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${MAKE_ENV} ${GMAKE} -C ${BUILD_PREFIX}/gdb install-pdf >> ${WRKDIR}/gdb.log 2>&1
.endif

install-samples:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "====>  Install samples into stage directory"
	@${TAR} -xf ${SRC_DIR}/samples.tar.bz2 -C ${INTERIM_PREFIX}/share/gcc-${TARGET}
.else
	@${DO_NADA}
.endif

install-misc:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "====>  Install misc. files into stage directory"
	@for doc in ${MISC_DOCS} ; do \
	 ${CP} -f ${WRKDIR}/${ORIGINAL_PACKAGE_NAME}/$${doc} ${DOC_PREFIX}/ ; \
	 done
.else
	@${DO_NADA}
.endif

strip-binaries:
	@${ECHO_MSG} "====>  Strip host binaries"
	@for bin in $$(${FIND} ${INTERIM_PREFIX}/bin -type f -name ${TARGET}-\*) ; do \
	   if ! ${FILE} $$bin | ${GREP} -qs ': ELF' ; then continue ; fi ; \
	   ${STRIP_CMD} $${bin} ; \
	 done
	@for bin in $$(${FIND} ${INTERIM_PREFIX}/${TARGET}/bin -type f -maxdepth 1 -mindepth 1) ; do \
	   if ! ${FILE} $$bin | ${GREP} -qs ': ELF' ; then continue ; fi ; \
	   ${STRIP_CMD} $${bin} ; \
	 done
	@for bin in $$(${FIND} ${INTERIM_PREFIX}/lib/gcc/${TARGET}/4.8.3 -maxdepth 1 -perm +111 -and ! -type d) ; do \
	   if ! ${FILE} $$bin | ${GREP} -qs ': ELF' ; then continue ; fi ; \
	   ${STRIP_CMD} $${bin} ; \
	 done

strip-target-libraries:
	@${ECHO_MSG} "====>  Strip target libraries"
	@for target in $$(${FIND} ${INTERIM_PREFIX}/${TARGET}/lib ${INTERIM_PREFIX}/lib/gcc/${TARGET}/4.8.3 -type f -name \*.a -o -name \*.o) ; do \
	   ${INTERIM_PREFIX}/bin/${TARGET}-objcopy -R .comment -R .note -R .debug_info -R .debug_aranges -R .debug_pubnames -R .debug_pubtypes -R .debug_abbrev -R .debug_line -R .debug_str -R .debug_ranges -R .debug_loc $${target} ; \
	done
	@${ECHO_MSG} "====>  Remove *.la files and other leftovers"
	@${FIND} ${INTERIM_PREFIX} -name \*.la -delete
	@${RM} -f ${INTERIM_PREFIX}/lib/charset.alias ${INTERIM_PREFIX}/lib/libiberty.a
