# Created by: ports@FreeBSD.org
# $FreeBSD$

PORTNAME=	libexif-gtk
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/libexif/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	GTK+ widgets to display/edit EXIF tags

LICENSE=	LGPL21

LIB_DEPENDS=	libexif.so:graphics/libexif

GNU_CONFIGURE=	yes
USES=		gnome libtool pkgconfig
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} 's|-g -Wall|-Wall|' ${WRKSRC}/configure

.include <bsd.port.mk>
