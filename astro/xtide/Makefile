# New ports collection makefile for:   xtide
# Date created:        30 August 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	xtide
PORTVERSION=	2.2
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} harmonics.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	patseal@hyperhost.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		png.3:${PORTSDIR}/graphics/png

# www.universe.digex.net is broken
FETCH_BEFORE_ARGS=	-t

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
MAN1=	xtide.1 tide.1
MAN8=	xttpd.8
MANCOMPRESSED=	no

post-extract:
	@${GZCAT} ${DISTDIR}/harmonics.gz > ${WRKSRC}/harmonics

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tide ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xttpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/xtide.1 ${PREFIX}/man/man1/xtide.1
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/tide.1 ${PREFIX}/man/man1/tide.1
	${INSTALL_MAN} ${WRKSRC}/DOCUMENTATION/xttpd.8 ${PREFIX}/man/man8/xttpd.8
	@${MKDIR} ${PREFIX}/share/xtide
	${INSTALL_DATA} ${WRKSRC}/harmonics ${PREFIX}/share/xtide

.include <bsd.port.mk>
