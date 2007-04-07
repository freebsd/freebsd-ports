# ex:ts=8
# Ports collection makefile for:	ggz-gtk-games
# Date created:			Feb. 19, 2006
# Whom:				yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-gtk-games
PORTVERSION=	${GGZ_VERSION}
CATEGORIES=	games

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - GTK+ Games

RUN_DEPENDS=	${LOCALBASE}/bin/ggz-gtk:${PORTSDIR}/games/ggz-gtk-client

USE_GNOME=	gnometarget gtk20
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/libggz/bsd.ggz.mk"
.include <bsd.port.post.mk>
