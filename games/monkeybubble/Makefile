# New ports collection makefile for:	monkeybubble
# Date created:				06 October 2003
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	monkeybubble
PORTVERSION=	0.3.2
CATEGORIES=	games gnome
MASTER_SITES=	http://home.gna.org/monkeybubble/downloads/
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix librsvg2 libgnomeui \
		gstreamerplugins intlhack

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
