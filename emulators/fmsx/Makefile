# New ports collection makefile for:    fMSX
# Date created:         15 Oct 1996
# Whom:                 dk
#
# $FreeBSD$
#

PORTNAME=	fmsx
PORTVERSION=	2.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/fms/fMSX/
DISTNAME=	fMSX22
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dk@farm.org

USE_XLIB=	yes
NO_PACKAGE=	${RESTRICTED}
RESTRICTED=	Legal status of distributed ROM images unclear
WRKSRC=		${WRKDIR}/MSX

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fmsx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fmsx ${PREFIX}/bin/fmsx.bin
	${INSTALL_PROGRAM} ${WRKSRC}/rddsk ${PREFIX}/bin/fmsx-rddsk
	${INSTALL_PROGRAM} ${WRKSRC}/wrdsk ${PREFIX}/bin/fmsx-wrdsk
	${MKDIR} ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/*.ROM ${WRKSRC}/*.FNT ${PREFIX}/share/fmsx
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fmsx
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/fmsx
.endif

.include <bsd.port.mk>
