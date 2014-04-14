# Created by: Ruben <chromium@hybridsource.org>
# $FreeBSD$

PORTNAME=	dmd
PORTVERSION=	1.076
PKGNAMESUFFIX=	1
CATEGORIES=	lang
MASTER_SITES=	http://ftp.digitalmars.com/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Official compiler for the D 1.0 programming language

NO_PACKAGE=	Packages are not validation-tested by the developer
USES=		gmake zip
PORTDOCS=	*.txt html/ phobos/
WRKSRC=		${WRKDIR}/${PORTNAME}/src/${PORTNAME}
LICENSE_COMB=	multi
LICENSE=	ART10 ZLIB DMD
LICENSE_NAME_DMD=	digital mars license
LICENSE_FILE_DMD=	${WRKSRC}/../../license.txt
LICENSE_PERMS_DMD=	no-pkg-mirror auto-accept

OPTIONS_DEFINE=	SOURCE DOCS
SOURCE_DESC=	Compile dmd and phobos from source

.include <bsd.port.options.mk>

MODULEDIR=	${PREFIX}/include/d/phobos

.if ${PORT_OPTIONS:MSOURCE}
MAKEFILE=	posix.mak
.else
NO_BUILD=	yes
.endif

.if ${ARCH} == "amd64"
MAKE_ARGS+=	MODEL=64
.else
MAKE_ARGS+=	MODEL=32
.endif

post-patch:
.if ${PORT_OPTIONS:MSOURCE}
	@${REINPLACE_CMD} -e "s|gcc|${CC}|"			\
		${WRKSRC}/../phobos/freebsd.mak			\
		${WRKSRC}/../phobos/etc/c/zlib/freebsd.mak	\
		${WRKSRC}/../phobos/internal/gc/freebsd.mak
	@${REINPLACE_CMD} -e "s|g++|${CXX}|"			\
		${WRKSRC}/../phobos/freebsd.mak
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|"	\
		${WRKDIR}/dmd/man/man1/dmd.1		\
		${WRKDIR}/dmd/man/man1/dmd.conf.5
	@${REINPLACE_CMD} -e 's|"/etc/"|"${PREFIX}/etc/"|' ${WRKSRC}/inifile.c
	@${REINPLACE_CMD} -e 's|dmd.conf|dmd2.conf|' ${WRKSRC}/mars.c
.endif
	@${REINPLACE_CMD} -e "s|%@P%/../../src/phobos|${MODULEDIR}|" ${WRKDIR}/dmd/freebsd/bin32/dmd.conf
	@${CP} ${WRKDIR}/dmd/freebsd/bin32/dmd.conf ${WRKDIR}/dmd/freebsd/bin32/dmd.conf.tango
	@${REINPLACE_CMD} -e "s|phobos|tango -defaultlib=tango -version=freebsd|" ${WRKDIR}/dmd/freebsd/bin32/dmd.conf.tango
	@${REINPLACE_CMD} -e "1s|^|# You'll need to recompile libtango.a with dmd and install it yourself.|" ${WRKDIR}/dmd/freebsd/bin32/dmd.conf.tango
	@${REINPLACE_CMD} -e "s|%@P%/../lib|${PREFIX}/lib|" \
		${WRKDIR}/dmd/freebsd/bin32/dmd.conf	\
		${WRKDIR}/dmd/freebsd/bin32/dmd.conf.tango

post-build:
	@${REINPLACE_CMD} -e "s| etc/c/zlib/gzio.o||" ${WRKSRC}/../phobos/freebsd.mak

do-install:
	${INSTALL_MAN} ${WRKDIR}/dmd/man/man1/dmd.1 ${STAGEDIR}${MANPREFIX}/man/man1/dmd1.1
	${INSTALL_MAN} ${WRKDIR}/dmd/man/man1/dmd.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5/dmd1.conf.5
.if !exists(${STAGEDIR}${PREFIX}/etc/dmd.conf)
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin32/dmd.conf ${STAGEDIR}${PREFIX}/etc
.endif
	${INSTALL_PROGRAM} ${WRKDIR}/dmd/freebsd/bin32/dmd ${STAGEDIR}${PREFIX}/bin/dmd1
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/lib32/libphobos.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin32/dmd.conf ${STAGEDIR}${EXAMPLESDIR}/dmd1.conf
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin32/dmd.conf.tango ${STAGEDIR}${EXAMPLESDIR}/dmd1.conf.tango
	cd ${WRKDIR}/dmd && ${COPYTREE_SHARE} samples ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${MODULEDIR}
	${INSTALL_DATA} ${WRKSRC}/../phobos/*.d ${STAGEDIR}${MODULEDIR}
	${MKDIR} ${STAGEDIR}${MODULEDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/gamma.d ${STAGEDIR}${MODULEDIR}/etc
	${MKDIR} ${STAGEDIR}${MODULEDIR}/etc/c
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/c/zlib.d ${STAGEDIR}${MODULEDIR}/etc/c
	cd ${WRKSRC}/../phobos && ${COPYTREE_SHARE} std ${STAGEDIR}${MODULEDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/dmd && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/phobos
	${INSTALL_DATA} ${WRKSRC}/../phobos/phoboslicense.txt ${STAGEDIR}${DOCSDIR}/phobos
	${INSTALL_DATA} ${WRKSRC}/../phobos/std.ddoc ${STAGEDIR}${DOCSDIR}/phobos
.endif

.include <bsd.port.mk>
