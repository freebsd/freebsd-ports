# New ports collection makefile for:    fMSX
# Date created:         15 Oct 1996
# Whom:                 dk
#
# $FreeBSD$
#

PORTNAME=	fmsx
PORTVERSION=	1.5
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/fms/fMSX/
DISTNAME=       fMSX
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	dk@farm.org

USE_XLIB=	yes
NO_PACKAGE=	${RESTRICTED}
RESTRICTED=	Legal status of distributed ROM images unclear
WRKSRC=         ${WRKDIR}/MSX

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fmsx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fmsx ${PREFIX}/bin/fmsx.bin
	${INSTALL_PROGRAM} ${WRKSRC}/dasm ${PREFIX}/bin/fmsx-dasm
	${INSTALL_PROGRAM} ${WRKSRC}/rddsk ${PREFIX}/bin/fmsx-rddsk
	${INSTALL_PROGRAM} ${WRKSRC}/wrdsk ${PREFIX}/bin/fmsx-wrdsk
	${MKDIR} ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/*.ROM ${WRKSRC}/*.FNT ${PREFIX}/share/fmsx
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fmsx
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/fmsx
.endif

.include <bsd.port.mk>
