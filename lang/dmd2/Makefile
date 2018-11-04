# Created by: Ruben <chromium@hybridsource.org>
# $FreeBSD$

PORTNAME=	dmd
PORTVERSION=	2.073.2
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
PKGNAMESUFFIX=	2

MAINTAINER=	cy@FreeBSD.org
COMMENT=	D 2.0 compiler, not officially validated for FreeBSD

LICENSE=	ART10 DMD BSL
LICENSE_COMB=	multi
LICENSE_NAME_DMD=	Digital Mars license
LICENSE_FILE_DMD=	${WRKSRC}/dmd/src/backendlicense.txt
LICENSE_PERMS_DMD=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

BROKEN=		fails to build
BROKEN_armv6=		dumps core: Assertion failed: (!signbit(Port::ldbl_nan)), function PortInitializer, file port.c
BROKEN_armv7=		dumps core: Assertion failed: (!signbit(Port::ldbl_nan)), function PortInitializer, file port.c
BROKEN_mips64=		fails to compile: cc1: unrecognized command line option -m32
BROKEN_powerpc64=	fails to build: can't mangle function with unknown linkage (void*())
BROKEN_sparc64=		fails to install: divide-by-zero error
BROKEN_FreeBSD_12=	stack corruption in generated dmd tool caused by inode64 resulting in segfault
BROKEN_FreeBSD_13=	stack corruption in generated dmd tool caused by inode64 resulting in segfault
NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	no cpu specified, assuming X86

USE_GITHUB=	nodefault
GH_ACCOUNT=	dlang
GH_PROJECT=	dmd:dmd druntime:druntime phobos:phobos dlang.org:dlang_org
USES=		gmake
MAKEFILE=	posix.mak
MAKE_ARGS=	HOST_DMD=${WRKDIR}/.host_dmd-2.067.1/stage/usr/local/bin/dmd
EXAMPLESDIR=	${PREFIX}/share/examples/dmd2
DOCSDIR=	${PREFIX}/share/doc/dmd2
WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKSRC_dmd} ${WRKSRC}/dmd
	@${MV} ${WRKSRC_druntime} ${WRKSRC}/druntime
	@${MV} ${WRKSRC_phobos} ${WRKSRC}/phobos
	@${MV} ${WRKSRC_dlang_org} ${WRKSRC}/dlang.org

.if ${ARCH} == "amd64"
MAKE_ARGS+=	MODEL=64
MODEL=		64
.else
MAKE_ARGS+=	MODEL=32
MODEL=		32
.endif

.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG_FLAGS=-g\ -DDEBUG=1\ -DUNITTEST BUILD=debug
.endif

MODULEDIR=	${PREFIX}/include/d/phobos2

post-patch:
	@${REINPLACE_CMD} -e "s|g++|${CXX}|" \
			  -e "s|/etc|${PREFIX}/etc|" \
		${WRKSRC}/dmd/src/posix.mak
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" ${WRKSRC}/dmd/src/link.d
	@${REINPLACE_CMD} -e "s|cc|${CC}|" ${WRKSRC}/phobos/posix.mak
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|"	\
			  -e "s|\(dmd\)|\12|gI"		\
			  -e "s|\\\BR|.BR|"		\
		${WRKDIR}/dmd/docs/man/man1/dmd.1		\
		${WRKDIR}/dmd/docs/man/man5/dmd.conf.5
	@${REINPLACE_CMD} -e "s|%@P%/../../src/phobos|${MODULEDIR}|"	\
			  -e "s|%@P%/../lib|${PREFIX}/lib|"		\
			  -e "s|%@P%/../../src/druntime|${PREFIX}/include/d/druntime|"	\
			  ${WRKDIR}/dmd/ini/freebsd/bin${MODEL}/dmd.conf
	@${ECHO_CMD} >> ${WRKDIR}/dmd/ini/freebsd/bin${MODEL}/dmd.conf

make-phobos:
	cd ${WRKSRC}/phobos && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -f ${MAKEFILE} ${BUILD}

make-druntime:
	cd ${WRKSRC}/druntime && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -f ${MAKEFILE} ${BUILD}

make-dmd:
	cd ${WRKSRC}/dmd && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -f ${MAKEFILE} ${BUILD}

do-build: make-dmd make-phobos make-druntime

do-install:
	${INSTALL_MAN} ${WRKDIR}/dmd/docs/man/man1/dmd.1 ${STAGEDIR}${MANPREFIX}/man/man1/dmd.1
	${INSTALL_MAN} ${WRKDIR}/dmd/docs/man/man5/dmd.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5/dmd.conf.5
	${INSTALL_DATA} ${WRKDIR}/dmd/ini/freebsd/bin${MODEL}/dmd.conf ${STAGEDIR}${PREFIX}/etc/dmd.conf
	${INSTALL_PROGRAM} ${WRKSRC}/dmd/src/dmd ${STAGEDIR}${PREFIX}/bin/dmd
	${INSTALL_DATA} ${WRKSRC}/phobos/generated/freebsd/release/${MODEL}/libphobos2.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd/ini/freebsd/bin${MODEL}/dmd.conf ${STAGEDIR}${PREFIX}/etc/dmd.conf.sample
	cd ${WRKDIR}/druntime/import && ${COPYTREE_SHARE} . ${STAGEDIR}${MODULEDIR}
	cd ${WRKSRC}/phobos && ${COPYTREE_SHARE} std ${STAGEDIR}${MODULEDIR}
	cd ${WRKSRC}/phobos && ${COPYTREE_SHARE} etc ${STAGEDIR}${MODULEDIR}

post-install-DOCS-on:
	cd ${WRKSRC}/dlang.org && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -f ${MAKEFILE} html ${BUILD} LATEST=${PORTVERSION}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dmd/*.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/dlang.org/web && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKDIR}/dmd && ${COPYTREE_SHARE} samples ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd/ini/freebsd/bin32/dmd.conf ${STAGEDIR}${EXAMPLESDIR}/dmd32.conf
	${INSTALL_DATA} ${WRKDIR}/dmd/ini/freebsd/bin64/dmd.conf ${STAGEDIR}${EXAMPLESDIR}/dmd64.conf

pre-fetch:
	${MAKE} -f Makefile.bootstrap BOOTDIR=${WRKDIR} checksum

pre-configure:
	${MAKE} -f Makefile.bootstrap BOOTDIR=${WRKDIR}

.include <bsd.port.mk>
