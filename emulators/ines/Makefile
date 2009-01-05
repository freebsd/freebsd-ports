# New ports collection makefile for:	ines
# Date created:		02 November 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ines
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/iNES/
DISTNAME=	iNES30-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo Entertainment System emlator for X

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	is an i386 binary

NO_WRKSUBDIR=	yes
USE_XORG=	x11 xext
NO_BUILD=	yes
STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ines ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/iNES.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CART.NES ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.pal ${DATADIR}

.include <bsd.port.mk>
