# New ports collection makefile for:	nabi
# Date created:		5 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nabi
PORTVERSION=	0.1
CATEGORIES=	korean gnome x11
MASTER_SITES=	http://download.kldp.net/imhangul/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" LIBS="-L${X11BASE}/lib"

post-patch:
	${REINPLACE_CMD} -e 's,#include <malloc.h>,,' ${WRKSRC}/IMdkit/IMConn.c

post-install:
	cd ${WRKSRC}/po && ${MAKE} install-data-yes

.include <bsd.port.mk>
