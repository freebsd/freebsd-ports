# New ports collection makefile for:	nabi
# Date created:		5 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nabi
PORTVERSION=	0.3
CATEGORIES=	korean gnome x11
MASTER_SITES=	http://download.kldp.net/nabi/

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

.include <bsd.port.mk>
