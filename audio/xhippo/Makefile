# Created by: Rod Taylor <rod@zort.on.ca>
# $FreeBSD$

PORTNAME=	xhippo
PORTVERSION=	3.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic music player for Unix-like systems

BROKEN=		unfetchable

LICENSE=	GPLv3

LIB_DEPENDS=	libid3tag.so:audio/libid3tag
RUN_DEPENDS=	mpg123:audio/mpg123

USE_GNOME=	gtk20
USES=		gettext gnome pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		xhippo

post-extract:
	@${LN} -sf xhippo.config ${WRKSRC}/xhippo.config.sample

post-patch:
	@${REINPLACE_CMD} -e \
		'/^sysconf_DATA/s|=.*|= xhippo.config.sample|' \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
