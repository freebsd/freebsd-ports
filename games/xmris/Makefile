# New ports collection makefile for:    xmris
# Date created:         21 September 1994
# Whom:                 jmz
#
# $FreeBSD$

PORTNAME=	xmris
PORTVERSION=	4.04
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A version of the Mr Do video arcade game for X11

USE_IMAKE=	yes
MAKE_FLAGS=	XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults -f
ALL_TARGET=	xmris xmred
MAN6=		xmred.6 xmris.6 xmsit.6
USE_REINPLACE=  yes

post-configure:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's/MANSUFFIX = 1/MANSUFFIX = 6/' \
	  -e 's/OWNER = -o games/OWNER = -g games/' \
	  -e 's/^INSTMRISFLAGS.*/INSTMRISFLAGS = \$(OWNER) -m 2555/' Makefile

post-install:
	@${CHMOD} g+w ${X11BASE}/lib/X11/xmris

.include <bsd.port.mk>
