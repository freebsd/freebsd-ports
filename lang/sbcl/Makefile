# $FreeBSD$
#
# Note: If you update this port make sure you create the distfinfo for all
# versions: sbcl-1.v.v-x86-64-freebsd and sbcl-1.v.v-x86-freebsd
#

PORTNAME=	sbcl
PORTVERSION=	1.1.3
PORTEPOCH=	1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.SpringDaemons.com/soft/sbcl-binary/:binaries
DISTFILES=	\
	${PORTNAME}-${PORTVERSION}-source${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A Common Lisp development system derived from the CMU CL system

USE_BZIP2=	yes
USE_GMAKE=	yes

OPTIONS_DEFINE =	SBCL THREADS

SBCL_DESC=	Bootstrap with installed SBCL binary, if available
THREADS_DESC=	Experimental threading support

CONTRIB_MODULES=	asdf			\
			asdf-install		\
			sb-aclrepl		\
			sb-bsd-sockets		\
			sb-cltl2		\
			sb-concurrency		\
			sb-cover		\
			sb-executable		\
			sb-grovel		\
			sb-introspect		\
			sb-md5			\
			sb-posix		\
			sb-queue		\
			sb-rotate-byte		\
			sb-rt			\
			sb-simple-streams	\
			sb-sprof
MAN1=		sbcl.1
NEWBOOTNAME=	${PORTNAME}-${PORTVERSION}-${ARCH}-freebsd${OSREL:R}
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	is a native code compiler, and has not been ported to\
this architecture yet
SBCL_HOME=	${PREFIX}/lib/sbcl

.include <bsd.port.options.mk>

CFLAGS+=	-fno-omit-frame-pointer
CPPFLAGS+=	-I. -DSBCL_PREFIX=\\\"\$$(SBCL_PREFIX)\\\"

.if ${ARCH} == "i386"
DYNAMIC_SPACE_SIZE?=	512
PLIST_SUB+=	I386_ONLY="" AMD64_ONLY="@comment "
SBCLCONFIG=	 Config.x86-freebsd
.else
DYNAMIC_SPACE_SIZE?=	1024
PLIST_SUB+=	I386_ONLY="@comment " AMD64_ONLY=""
SBCLCONFIG=	Config.x86-64-freebsd
.endif

MAKE_SH_ARGS?=	--prefix=${PREFIX} --dynamic-space-size=${DYNAMIC_SPACE_SIZE} \
--with-sb-core-compression --with-sb-qshow
NM?=	/usr/bin/nm
NMFLAGS?=	-gp

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	\
	${PORTNAME}-${PORTVERSION}-documentation-html${EXTRACT_SUFX}
MANUALS=	asdf.html sbcl.html
MODULESDOCS=	asdf/README asdf/README.SBCL	\
		asdf-install/README 		\
		sb-aclrepl/README		\
		sb-bsd-sockets/FAQ sb-bsd-sockets/NEWS \
		sb-md5/README			\
		sb-posix/README			\
		sb-rotate-byte/README		\
		sb-simple-streams/README
TEXTDOCS=	BUGS CREDITS COPYING NEWS PRINCIPLES TLA TODO
.endif

# If the SBCL option is enabled, try to use existing "sbcl" first:
.if empty(PORT_OPTIONS:MSBCL) || !exists(${LOCALBASE}/bin/sbcl) || make(makesum)
BOOT_VERSION=	1.0.31

. if make(makesum)
BOOT_ARCH_OS_LIST=	amd64-freebsd8 amd64-freebsd7 i386-freebsd8 \
			i386-freebsd7
. else
.  if ${OSREL:R} > 8	# We'll use 8.x bootstrap for now
BOOT_ARCH_OS_LIST=	${ARCH}-freebsd8
.  else
BOOT_ARCH_OS_LIST=	${ARCH}-freebsd${OSREL:R}
.  endif
. endif

. for BOOT_ARCH_OS in ${BOOT_ARCH_OS_LIST}
BOOT_DISTNAME=	${PORTNAME}-${BOOT_VERSION}-${BOOT_ARCH_OS}
DISTFILES:=	${DISTFILES} ${BOOT_DISTNAME}-binary${EXTRACT_SUFX}:binaries
. endfor

XC_HOST?=	${WRKDIR}/${BOOT_DISTNAME}/src/runtime/sbcl --core \
${WRKDIR}/${BOOT_DISTNAME}/output/sbcl.core \
--dynamic-space-size ${DYNAMIC_SPACE_SIZE} \
--disable-debugger --userinit /dev/null --sysinit /dev/null
MAKE_SH_ARGS+=	--xc-host='${XC_HOST}'

.endif # SBCL

.if ${PORT_OPTIONS:MTHREADS}
MAKE_SH_ARGS+=	--with-sb-thread
.if defined(WITH_FUTEX)
MAKE_SH_ARGS+=	--with-sb-futex
.else
MAKE_SH_ARGS+=	--without-sb-futex
.endif
.if defined(WITH_SAFEPOINT) || defined(WITH_STRICT_SAFEPOINT)
MAKE_SH_ARGS+=	--with-sb-safepoint --with-sb-thruption --with-sb-wtimer
.if defined(WITH_STRICT_SAFEPOINT)
MAKE_SH_ARGS+=	--with-sb-safepoint-strictly
.else
MAKE_SH_ARGS+=	--without-sb-safepoint-strictly
.endif
.else
MAKE_SH_ARGS+=	--without-sb-safepoint --without-sb-safepoint-strictly \
		--without-sb-thruption --without-sb-wtimer
.endif
.else
MAKE_SH_ARGS+=	--without-sb-thread
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG} "You might need to adjust memory limits in order to"
	@${ECHO_MSG} "build SBCL."
	@${ECHO_MSG}
	@${ECHO_MSG} "You can use the DYNAMIC_SPACE_SIZE knob to change the size"
	@${ECHO_MSG} "of SBCL dynamically-allocated memory."
	@${ECHO_MSG} "---------------------------------------------------------"
	@${ECHO_MSG}

post-patch:
	@${ECHO_CMD} "CC=${CC}" >> ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "CFLAGS=${CFLAGS}" >> \
		${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "CPPFLAGS=${CPPFLAGS}" >> \
		${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "GREP=${GREP}" >> ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "LD=${LD}" >> ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "LINKFLAGS=${LDFLAGS} -dynamic -rdynamic" >> \
		${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${ECHO_CMD} "NM=${NM} ${NMFLAGS}" >> \
		${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${REINPLACE_CMD} -E -e 's,-lthr,-pthread,g' \
	    -e 's,-lpthread,-pthread,g' ${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${GREP} -Fe '.core' -l -r ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
	-e 's|\.core|_core|g'
	@${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/doc/sbcl.1
	@${REINPLACE_CMD} -E -e 's!-sbcl-shared!& ${CFLAGS}!' \
		-e 's!\$$(TEST_FILESTEM|1)_core!$${\1}_core!g' \
		${WRKSRC}/tests/core.test.sh \
		${WRKSRC}/tests/foreign.test.sh
	@${REINPLACE_CMD} -E -e 's!"-O3"!!' \
		-e 's!("-sbcl-(pic|shared)"[[:blank:]]*)+!& ${CFLAGS:C/.*/"&"/}!' \
		${WRKSRC}/tests/foreign-stack-alignment.impure.lisp \
		${WRKSRC}/tests/kill-non-lisp-thread.impure.lisp \
		${WRKSRC}/tests/swap-lispobjs.impure.lisp \
		${WRKSRC}/tests/threads.impure.lisp
	@${REINPLACE_CMD} -e 's|( cd ./doc ; sh ./clean.sh )|#&|' \
		${WRKSRC}/clean.sh

do-build:
	@${FIND} ${WRKSRC} \( -name '*.orig' -o -name '*.bak' \) -delete
	@(cd ${WRKSRC} && ${SETENV} CC="${CC}" ${SH} make.sh ${MAKE_SH_ARGS})
	@${RM} -rf ${WRKSRC}/contrib/sb-cover/test-output
	@${REINPLACE_CMD} -E -e \
		's|\$$Date\$$|'"`${SETENV} LANG=C /bin/date '+%B %d, %Y'`|g" \
		${WRKSRC}/doc/sbcl.1

do-install:
	${MKDIR} ${SBCL_HOME}/
	${INSTALL_PROGRAM} ${WRKSRC}/src/runtime/sbcl ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/output/sbcl_core ${SBCL_HOME}/
.for MOD in ${CONTRIB_MODULES}
	${MKDIR} ${SBCL_HOME}/${MOD}
	${INSTALL_DATA} ${WRKSRC}/contrib/${MOD}/*.lisp ${SBCL_HOME}/${MOD}/
	${INSTALL_DATA} ${WRKSRC}/contrib/${MOD}/*.fasl ${SBCL_HOME}/${MOD}/
	(if test -f ${WRKSRC}/contrib/${MOD}/${MOD}.asd; then ${INSTALL_DATA} \
	    ${WRKSRC}/contrib/${MOD}/${MOD}.asd ${SBCL_HOME}/${MOD}/; fi)
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${MANUALS:S,^, ${WRKSRC}/doc/manual/,g} ${DOCSDIR}/
	${INSTALL_DATA} ${TEXTDOCS:S,^,${WRKSRC}/,g} ${DOCSDIR}/
	${MKDIR} ${MODULESDOCS:C,/[^/]+$,,g:u:S,^,${DOCSDIR}/,g}
. for MODDOC in ${MODULESDOCS}
	${INSTALL_DATA} ${WRKSRC}/contrib/${MODDOC} ${DOCSDIR}/${MODDOC}
. endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/sbcl.1 ${MAN1PREFIX}/man/man1
	${MKDIR} ${SBCL_HOME}/site-systems
	@${TOUCH} ${SBCL_HOME}/site-systems/.keep_me

check regression-test test: build
	(cd ${WRKSRC}/tests && ${SETENV} CC="${CC}" ${SH} run-tests.sh)

bootstrap:
	${CP} -r ${WRKSRC} ${WRKDIR}/${NEWBOOTNAME}
	(cd ${WRKDIR}/ && \
	    ${WRKDIR}/${NEWBOOTNAME}/binary-distribution.sh ${NEWBOOTNAME})
	(cd ${WRKDIR}/ && ${BZIP2_CMD} ${NEWBOOTNAME}-binary.tar)

.include <bsd.port.mk>
