# New ports collection makefile for:	dmd
# Date created:				November 15 2010
# Whom:					Ruben <chromium@hybridsource.org>
#
# $FreeBSD$
#

PORTNAME=	dmd
PORTVERSION=	1.067
CATEGORIES=	lang
MASTER_SITES=	http://ftp.digitalmars.com/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Official compiler for the D 1.0 programming language

NO_PACKAGE=	Packages are not validation-tested by the developer
ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
MAN1=		dmd.1
MAN5=		dmd.conf.5
PORTDOCS=	*.txt html/ phobos/
WRKSRC=		${WRKDIR}/${PORTNAME}/src/${PORTNAME}
LICENSE_COMB=	multi
LICENSE=	ART10 ZLIB DMD
LICENSE_NAME_ZLIB=	zlib license
LICENSE_PERMS_ZLIB=	${_LICENSE_PERMS_DEFAULT}
LICENSE_FILE_ZLIB=	${WRKSRC}/../phobos/phoboslicense.txt
LICENSE_NAME_DMD=	digital mars license
LICENSE_FILE_DMD=	${WRKSRC}/../../license.txt
LICENSE_PERMS_DMD=	no-pkg-mirror auto-accept

OPTIONS=	SOURCE		"Compile dmd and phobos from source" off

.include <bsd.port.pre.mk>

MODULEDIR=	${PREFIX}/include/d/phobos

.if defined(WITH_SOURCE)
MAKEFILE=	freebsd.mak
.else
NO_BUILD=	yes
PLIST_FILES=	bin/dmd.conf
.endif

post-patch:
.if defined(WITH_SOURCE)
	@${REINPLACE_CMD} -e "s|gcc|${CC}|"			\
		${WRKSRC}/../phobos/freebsd.mak			\
		${WRKSRC}/../phobos/etc/c/zlib/freebsd.mak	\
		${WRKSRC}/../phobos/internal/gc/freebsd.mak	\
		${WRKSRC}/freebsd.mak
	@${REINPLACE_CMD} -e "s|g++|${CXX}|"			\
		${WRKSRC}/../phobos/freebsd.mak			\
		${WRKSRC}/freebsd.mak
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|"	\
		${WRKDIR}/dmd/man/man1/dmd.1		\
		${WRKDIR}/dmd/man/man1/dmd.conf.5
	@${REINPLACE_CMD} -e 's|"/etc/"|"${PREFIX}/etc/"|' ${WRKSRC}/inifile.c
.endif
	@${REINPLACE_CMD} -e "s|%@P%/../../src/phobos|${MODULEDIR}|" ${WRKDIR}/dmd/freebsd/bin/dmd.conf
	@${CP} ${WRKDIR}/dmd/freebsd/bin/dmd.conf ${WRKDIR}/dmd/freebsd/bin/dmd.conf.tango
	@${REINPLACE_CMD} -e "s|phobos|tango -defaultlib=tango -version=freebsd|" ${WRKDIR}/dmd/freebsd/bin/dmd.conf.tango
	@${REINPLACE_CMD} -e "1s|^|# You'll need to recompile libtango.a with dmd and install it yourself.|" ${WRKDIR}/dmd/freebsd/bin/dmd.conf.tango
	@${REINPLACE_CMD} -e "s|%@P%/../lib|${PREFIX}/lib|" \
		${WRKDIR}/dmd/freebsd/bin/dmd.conf	\
		${WRKDIR}/dmd/freebsd/bin/dmd.conf.tango

post-build:
	@${REINPLACE_CMD} -e "s| etc/c/zlib/gzio.o||" ${WRKSRC}/../phobos/freebsd.mak
	cd ${WRKSRC}/../phobos && \
		${SETENV} PATH=${PATH}:${WRKSRC} ${MAKE} ${MAKE_FLAGS} freebsd.mak

do-install:
	${INSTALL_MAN} ${WRKDIR}/dmd/man/man1/dmd.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/dmd/man/man1/dmd.conf.5 ${MANPREFIX}/man/man5
.if !exists(${PREFIX}/etc/dmd.conf)
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin/dmd.conf ${PREFIX}/etc
.endif
.if defined(WITH_SOURCE)
	${INSTALL_PROGRAM} ${WRKSRC}/dmd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../phobos/libphobos.a ${PREFIX}/lib
.else
	${INSTALL_PROGRAM} ${WRKDIR}/dmd/freebsd/bin/dmd ${PREFIX}/bin
	${LN} -sf ${PREFIX}/etc/dmd.conf ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/lib/libphobos.a ${PREFIX}/lib
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin/dmd.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/dmd/freebsd/bin/dmd.conf.tango ${EXAMPLESDIR}
	cd ${WRKDIR}/dmd && ${COPYTREE_SHARE} samples ${EXAMPLESDIR}
	${MKDIR} ${MODULEDIR}
	${INSTALL_DATA} ${WRKSRC}/../phobos/*.d ${MODULEDIR}
	${MKDIR} ${MODULEDIR}/etc
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/gamma.d ${MODULEDIR}/etc
	${MKDIR} ${MODULEDIR}/etc/c
	${INSTALL_DATA} ${WRKSRC}/../phobos/etc/c/zlib.d ${MODULEDIR}/etc/c
	cd ${WRKSRC}/../phobos && ${COPYTREE_SHARE} std ${MODULEDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	cd ${WRKDIR}/dmd && ${COPYTREE_SHARE} html ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/phobos
	${INSTALL_DATA} ${WRKSRC}/../phobos/phoboslicense.txt ${DOCSDIR}/phobos
	${INSTALL_DATA} ${WRKSRC}/../phobos/std.ddoc ${DOCSDIR}/phobos
.endif

.include <bsd.port.post.mk>
