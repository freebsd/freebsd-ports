# Created by: ijliao
# $FreeBSD$

PORTNAME=	ggz-gtk-client
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - GTK+ Frontend

USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

MAN6=	ggz-gtk.6

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
