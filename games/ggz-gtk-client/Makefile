# Created by: ijliao
# $FreeBSD$

PORTNAME=	ggz-gtk-client
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	7
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - GTK+ Frontend

USES=		libtool:oldver
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client
USES=		pkgconfig

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
