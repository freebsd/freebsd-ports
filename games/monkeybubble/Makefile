# New ports collection makefile for:	monkeybubble
# Date created:				06 October 2003
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	monkeybubble
PORTVERSION=	0.1.9
CATEGORIES=	games gnome
#MASTER_SITES=	http://monkey-bubble.tuxfamily.org/ #OMG where did the website go?!?!
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix librsvg2 libgnomeui \
		gstreamerplugins intlhack

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
