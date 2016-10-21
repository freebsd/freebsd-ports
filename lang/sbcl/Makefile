# $FreeBSD$

PORTNAME=	sbcl
PORTVERSION=	1.3.1
PORTEPOCH=	1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/sbcl/sbcl/${PORTVERSION} LOCAL/marino:binaries
DISTFILES=	sbcl-${PORTVERSION}-source${EXTRACT_SUFX} \
		sbcl-${PORTVERSION}-documentation-html${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common Lisp development system derived from the CMU CL system

LICENSE=	sbcl
LICENSE_NAME=	public domain | FreeBSD
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept dist-sell pkg-sell

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake tar:bzip2

ONLY_FOR_ARCHS=	i386 amd64
SBCL_HOME=	${PREFIX}/lib/sbcl
MANUALS=	asdf.html sbcl.html
MODULESDOCS=	asdf/README.md 			\
		asdf/README.SBCL		\
		sb-aclrepl/README		\
		sb-bsd-sockets/FAQ 		\
		sb-bsd-sockets/NEWS 		\
		sb-gmp/README.md 		\
		sb-md5/README			\
		sb-mpfr/README.md		\
		sb-posix/README			\
		sb-rotate-byte/README		\
		sb-simple-streams/README
TEXTDOCS=	BUGS CREDITS COPYING NEWS PRINCIPLES TLA TODO
CFLAGS+=	-fno-omit-frame-pointer
CPPFLAGS+=	-I. -DSBCL_PREFIX=\\\"\$$(SBCL_PREFIX)\\\"
CONMODULES=	asdf sb-aclrepl sb-bsd-sockets sb-cltl2 sb-concurrency \
		sb-cover sb-executable sb-gmp sb-grovel sb-introspect \
		sb-md5 sb-mpfr sb-posix sb-queue sb-rotate-byte sb-rt \
		sb-simple-streams sb-sprof

MAKE_SH_ARGS?=	--prefix=${PREFIX} \
		--dynamic-space-size=${DYNAMIC_SPACE_SIZE} \
		--with-sb-core-compression \
		--with-sb-qshow
NM?=		/usr/bin/nm
NMFLAGS?=	-gp

BOOT_ARCH_OS_LIST=	1.0.31-amd64-freebsd8 1.0.31-i386-freebsd8 \
			1.2.9-x86_64-dragonfly4

OPTIONS_DEFINE=		SBCL #THREADS (don't build, see PR 184425)
SBCL_DESC=		Bootstrap with installed SBCL binary, if available
THREADS_DESC=		Experimental threading support

.include <bsd.port.options.mk>

NEWBOOTNAME=	sbcl-${PORTVERSION}-${ARCH}-${OPSYS:tl}${OSREL:R}
PATTERN=	*-${ARCH}-${OPSYS:tl}*
# FreeBSD hack is to support legacy make, add unrelated core fix while here
. if ${OPSYS} == FreeBSD
CORE=	sbcl.core
BOOT_DISTNAME=	sbcl-1.0.31-${ARCH}-freebsd8
. else # newer core format
CORE=	sbcl_core
BOOT_DISTNAME=	sbcl-${BOOT_ARCH_OS_LIST:M${PATTERN}}
. endif

.if make(makesum) || defined(FETCH_ALL)
. for BOOT_ARCH_OS in ${BOOT_ARCH_OS_LIST}
DISTFILES:=	${DISTFILES} sbcl-${BOOT_ARCH_OS}-binary.tar.bz2:binaries
. endfor
.else
DISTFILES:=	${DISTFILES} ${BOOT_DISTNAME}-binary.tar.bz2:binaries
.endif

.if ${ARCH} == "i386"
DYNAMIC_SPACE_SIZE?=	512
PLIST_SUB+=	I386_ONLY="" AMD64_ONLY="@comment "
SBCLCONFIG=	 Config.x86-${OPSYS:tl}
.else
DYNAMIC_SPACE_SIZE?=	1024
PLIST_SUB+=	I386_ONLY="@comment " AMD64_ONLY=""
SBCLCONFIG=	Config.x86-64-${OPSYS:tl}
.endif

# If the SBCL option is enabled, try to use existing "sbcl" first:
.if empty(PORT_OPTIONS:MSBCL) || !exists(${LOCALBASE}/bin/sbcl)
XC_HOST?=	${WRKDIR}/${BOOT_DISTNAME}/src/runtime/sbcl \
		--core ${WRKDIR}/${BOOT_DISTNAME}/output/${CORE} \
		--dynamic-space-size ${DYNAMIC_SPACE_SIZE} \
		--disable-debugger \
		--userinit /dev/null \
		--sysinit /dev/null
MAKE_SH_ARGS+=	--xc-host='${XC_HOST}'
.endif # SBCL

.if ${PORT_OPTIONS:MTHREADS}
MAKE_SH_ARGS+=	--with-sb-thread
. if defined(WITH_FUTEX)
MAKE_SH_ARGS+=	--with-sb-futex
. else
MAKE_SH_ARGS+=	--without-sb-futex
. endif
. if defined(WITH_SAFEPOINT) || defined(WITH_STRICT_SAFEPOINT)
MAKE_SH_ARGS+=	--with-sb-safepoint --with-sb-thruption --with-sb-wtimer
.  if defined(WITH_STRICT_SAFEPOINT)
MAKE_SH_ARGS+=	--with-sb-safepoint-strictly
.  else
MAKE_SH_ARGS+=	--without-sb-safepoint-strictly
.  endif
. else
MAKE_SH_ARGS+=	--without-sb-safepoint \
		--without-sb-safepoint-strictly \
		--without-sb-thruption \
		--without-sb-wtimer
. endif
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
	@${REINPLACE_CMD} -E -e 's,-lthr,-lpthread,g' \
		${WRKSRC}/src/runtime/${SBCLCONFIG}
	@${GREP} -Fe '.core' -l -r ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|\.core|_core|g'
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/doc/sbcl.1
	@${REINPLACE_CMD} -E -e 's!-sbcl-shared!& ${CFLAGS}!' \
		-e 's!\$$(TEST_FILESTEM|x|1)_core!$${\1}_core!g' \
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
	@case "`${CC} --version`" in \
		*clang*) \
			${REINPLACE_CMD} -e '/#define END()/s/\.end//' \
				${WRKSRC}/src/runtime/x86-assem.S \
				${WRKSRC}/src/runtime/x86-64-assem.S ;; \
	esac
	${REINPLACE_CMD} -e 's!/bin/bash!${LOCALBASE}&!' \
		${WRKSRC}/release.sh \
		${WRKSRC}/src/code/run-program.lisp \
		${WRKSRC}/tests/run-compiler.sh
	@${FIND} ${WRKSRC} \( -name '*.orig' -o -name '*.bak' \) -delete

do-build:
	(cd ${WRKSRC} && ${SETENV} CC="${CC}" ${SH} make.sh ${MAKE_SH_ARGS})
	${RM} -r ${WRKSRC}/contrib/sb-cover/test-output
	${REINPLACE_CMD} -E -e \
		's|\$$Date\$$|'"`${SETENV} LANG=C /bin/date '+%B %d, %Y'`|g" \
		${WRKSRC}/doc/sbcl.1

do-install:
	${MKDIR} ${STAGEDIR}${SBCL_HOME}/contrib \
		${STAGEDIR}${SBCL_HOME}/site-systems
	${INSTALL_PROGRAM} ${WRKSRC}/src/runtime/sbcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/output/sbcl_core ${STAGEDIR}${SBCL_HOME}
	${INSTALL_DATA} ${WRKSRC}/obj/sbcl-home/contrib/*.fasl \
		${STAGEDIR}${SBCL_HOME}/contrib/
	${INSTALL_DATA} ${WRKSRC}/obj/sbcl-home/contrib/*.asd \
		${STAGEDIR}${SBCL_HOME}/contrib/
.for MOD in ${CONMODULES}
	${MKDIR} ${STAGEDIR}${SBCL_HOME}/${MOD}
	- ${INSTALL_DATA} ${WRKSRC}/contrib/${MOD}/*.lisp \
		${STAGEDIR}${SBCL_HOME}/${MOD}
	- ${INSTALL_DATA} ${WRKSRC}/contrib/${MOD}/*.fasl \
		${STAGEDIR}${SBCL_HOME}/${MOD}
	- ${INSTALL_DATA} ${WRKSRC}/contrib/${MOD}/${MOD}.asd \
		${STAGEDIR}${SBCL_HOME}/${MOD}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${MANUALS:S,^, ${WRKSRC}/doc/manual/,g} \
		${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${TEXTDOCS:S,^,${WRKSRC}/,g} ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${MODULESDOCS:C,/[^/]+$,,g:u:S,^,${STAGEDIR}${DOCSDIR}/,g}
. for MODDOC in ${MODULESDOCS}
	${INSTALL_DATA} ${WRKSRC}/contrib/${MODDOC} \
		${STAGEDIR}${DOCSDIR}/${MODDOC}
. endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/sbcl.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

check regression-test test: build
	(cd ${WRKSRC}/tests && ${SETENV} CC="${CC}" ${SH} run-tests.sh)

bootstrap:
	${CP} -r ${WRKSRC} ${WRKDIR}/${NEWBOOTNAME}
	(cd ${WRKDIR}/ && \
	    ${WRKDIR}/${NEWBOOTNAME}/binary-distribution.sh ${NEWBOOTNAME})
	(cd ${WRKDIR}/ && ${BZIP2_CMD} ${NEWBOOTNAME}-binary.tar)

.include <bsd.port.mk>
