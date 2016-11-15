# Created by: Ruben <chromium@hybridsource.org>
# $FreeBSD$

PORTNAME=	dmd
PORTVERSION=	2.071.1
CATEGORIES=	lang
MASTER_SITES=	http://ftp.digitalmars.com/
PKGNAMESUFFIX=	2
DISTNAME=	dmd.${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	D 2.0 compiler, not officially validated for FreeBSD

LICENSE=	ART10 DMD BSL
LICENSE_COMB=	multi
LICENSE_NAME_DMD=	Digital Mars license
LICENSE_FILE_DMD=	${WRKSRC}/backendlicense.txt
LICENSE_PERMS_DMD=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

EXTRACT_ONLY=	${DISTNAME}.freebsd-64${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}.freebsd-64${EXTRACT_SUFX} \
		dmd.2.067.1.zip
# The souces in the following files can be used instead. Either way the
# binaries in the distribution are ignored. This port builds its own
# binaries using the sources that come with the distribution.
# DISTFILES=	${DISTNAME}.freebsd-32${EXTRACT_SUFX}
# DISTFILES=	${DISTNAME}.linux${EXTRACT_SUFX}

USES=		gmake zip
MAKEFILE=	posix.mak
MAKE_ARGS=	AUTO_BOOTSTRAP=1
MAKE_ENV+=	WRKDIR=${WRKDIR}
EXAMPLESDIR=	${PREFIX}/share/examples/dmd2
DOCSDIR=	${PREFIX}/share/doc/dmd2
PORTDOCS=	*.txt html/
WRKSRC=		${WRKDIR}/dmd2/src/${PORTNAME}

BROKEN_aarch64=		Does not configure: no cpu specified, assuming X86
BROKEN_mips64=		Does not compile: cc1: error: unrecognized command line option -m32
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not install: divide-by-zero error

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ARGS+=	MODEL=64
MODEL=		64
.else
MAKE_ARGS+=	MODEL=32
MODEL=		32
.endif

.if defined(WITH_DEBUG)
BUILD=		debug
MAKE_ARGS+=	DEBUG_FLAGS=-g\ -DDEBUG=1\ -DUNITTEST
.endif

MODULEDIR=	${PREFIX}/include/d/phobos2

post-patch:
	@${MKDIR} ${WRKDIR}/dmd2/freebsd/bin32 \
		${WRKDIR}/dmd2/freebsd/bin64 \
		${WRKDIR}/dmd2/freebsd/lib32 \
		${WRKDIR}/dmd2/freebsd/lib64
	@${REINPLACE_CMD} -e "s|g++|${CXX}|" \
			  -e "s|/etc|${PREFIX}/etc|" \
		${WRKSRC}/posix.mak
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" ${WRKSRC}/link.d
	@${REINPLACE_CMD} -e "s|cc|${CC}|" ${WRKSRC}/../phobos/posix.mak
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|"	\
			  -e "s|\(dmd\)|\12|gI"		\
			  -e "s|\\\BR|.BR|"		\
		${WRKDIR}/dmd2/man/man1/dmd.1		\
		${WRKDIR}/dmd2/man/man5/dmd.conf.5
	@${REINPLACE_CMD} -e "s|%@P%/../../src/phobos|${MODULEDIR}|"	\
			  -e "s|%@P%/../lib|${PREFIX}/lib|"		\
			  -e "s|%@P%/../../src/druntime|${PREFIX}/include/d/druntime|"	\
			  ${WRKDIR}/dmd2/freebsd/bin${MODEL}/dmd.conf
	@${ECHO_CMD} >> ${WRKDIR}/dmd2/freebsd/bin${MODEL}/dmd.conf

make-phobos:
	cd ${WRKSRC}/../phobos && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -f ${MAKEFILE} ${BUILD}

make-druntime:
	cd ${WRKSRC}/../druntime && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -f ${MAKEFILE} ${BUILD}

make-dmd:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -f ${MAKEFILE} ${BUILD}

do-build: make-dmd make-phobos make-druntime

do-install:
	${INSTALL_MAN} ${WRKDIR}/dmd2/man/man1/dmd.1 ${STAGEDIR}${MANPREFIX}/man/man1/dmd.1
	${INSTALL_MAN} ${WRKDIR}/dmd2/man/man5/dmd.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5/dmd.conf.5
	${INSTALL_DATA} ${WRKDIR}/dmd2/freebsd/bin${MODEL}/dmd.conf ${STAGEDIR}${PREFIX}/etc/dmd.conf.sample
	${INSTALL_PROGRAM} ${WRKSRC}/dmd ${STAGEDIR}${PREFIX}/bin/dmd
	${INSTALL_DATA} ${WRKSRC}/../../src/phobos/generated/freebsd/release/${MODEL}/libphobos2.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd2/freebsd/bin32/dmd.conf ${STAGEDIR}${EXAMPLESDIR}/dmd32.conf
	${INSTALL_DATA} ${WRKDIR}/dmd2/freebsd/bin64/dmd.conf ${STAGEDIR}${EXAMPLESDIR}/dmd64.conf
	cd ${WRKDIR}/dmd2 && ${COPYTREE_SHARE} samples ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${MODULEDIR}/etc/c
	${INSTALL_DATA} ${WRKSRC}/../phobos/*.d ${STAGEDIR}${MODULEDIR}
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/c/zlib.d ${STAGEDIR}${MODULEDIR}/etc/c
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/c/curl.d ${STAGEDIR}${MODULEDIR}/etc/c
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/c/sqlite3.d ${STAGEDIR}${MODULEDIR}/etc/c
	cd ${WRKSRC}/../phobos && ${COPYTREE_SHARE} std ${STAGEDIR}${MODULEDIR}
	${MKDIR} ${STAGEDIR}${MODULEDIR}/../druntime
	cd ${WRKSRC}/../druntime && ${COPYTREE_SHARE} import ${STAGEDIR}${MODULEDIR}/../druntime
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/dmd2 && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

pre-configure:
	${MAKE} -f Makefile.bootstrap BOOTDIR=${WRKDIR}

.include <bsd.port.post.mk>
