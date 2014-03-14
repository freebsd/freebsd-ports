# Created by: Ruben <chromium@hybridsource.org>
# $FreeBSD$

PORTNAME=	dmd
PORTVERSION=	1.076
CATEGORIES=	lang
MASTER_SITES=	http://ftp.digitalmars.com/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Official compiler for the D 1.0 programming language

NO_PACKAGE=	Packages are not validation-tested by the developer
USES=		gmake zip
MAN1=		dmd.1
MAN5=		dmd.conf.5
PORTDOCS=	*.txt html/ phobos/
WRKSRC=		${WRKDIR}/${PORTNAME}/src/${PORTNAME}
LICENSE_COMB=	multi
LICENSE=	ART10 ZLIB DMD
LICENSE_NAME_DMD=	digital mars license
LICENSE_FILE_DMD=	${WRKSRC}/../../license.txt
LICENSE_PERMS_DMD=	no-pkg-mirror auto-accept

OPTIONS_DEFINE=	SOURCE DOCS
SOURCE_DESC=	Compile dmd and phobos from source

NO_STAGE=	yes
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
	${INSTALL_MAN} ${WRKDIR}/dmd/man/man1/dmd.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/dmd/man/man1/dmd.conf.5 ${MANPREFIX}/man/man5
.if !exists(${PREFIX}/etc/dmd.conf)
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin32/dmd.conf ${PREFIX}/etc
.endif
	${INSTALL_PROGRAM} ${WRKDIR}/dmd/freebsd/bin32/dmd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/lib32/libphobos.a ${PREFIX}/lib
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin32/dmd.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin32/dmd.conf.tango ${EXAMPLESDIR}
	cd ${WRKDIR}/dmd && ${COPYTREE_SHARE} samples ${EXAMPLESDIR}
	${MKDIR} ${MODULEDIR}
	${INSTALL_DATA} ${WRKSRC}/../phobos/*.d ${MODULEDIR}
	${MKDIR} ${MODULEDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/gamma.d ${MODULEDIR}/etc
	${MKDIR} ${MODULEDIR}/etc/c
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/c/zlib.d ${MODULEDIR}/etc/c
	cd ${WRKSRC}/../phobos && ${COPYTREE_SHARE} std ${MODULEDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	cd ${WRKDIR}/dmd && ${COPYTREE_SHARE} html ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/phobos
	${INSTALL_DATA} ${WRKSRC}/../phobos/phoboslicense.txt ${DOCSDIR}/phobos
	${INSTALL_DATA} ${WRKSRC}/../phobos/std.ddoc ${DOCSDIR}/phobos
.endif

.include <bsd.port.mk>
