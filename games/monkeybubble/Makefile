# New ports collection makefile for:	monkeybubble
# Date created:				06 October 2003
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	monkeybubble
PORTVERSION=	0.1.7
CATEGORIES=	games gnome
MASTER_SITES=	http://monkey-bubble.tuxfamily.org/
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

LIB_DEPENDS=	gstplay-0.6:${PORTSDIR}/multimedia/gstreamer-plugins

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix librsvg2 libgnomeui

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/share|${LOCALBASE}/share| ; \
		s|lang or die|lang, 0777 or die|" ${WRKSRC}/intltool-merge.in

.include <bsd.port.mk>
