# New ports collection makefile for:	nabi
# Date created:		5 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nabi
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	korean gnome x11
MASTER_SITES=	http://download.kldp.net/imhangul/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Hangul X Input Method for Everywhere

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

post-patch:
	${REINPLACE_CMD} -e 's,#include <malloc.h>,,' ${WRKSRC}/IMdkit/IMConn.c
	${REINPLACE_CMD} -e '641s,g_free(keyboard_map->map);,,' \
		${WRKSRC}/src/ui.c

.include <bsd.port.mk>
