PORTNAME=	libexif-gtk
PORTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libexif/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	GTK+ widgets to display/edit EXIF tags

LICENSE=	LGPL21

LIB_DEPENDS=	libexif.so:graphics/libexif

GNU_CONFIGURE=	yes
USES=		gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} 's|-g -Wall|-Wall|' ${WRKSRC}/configure

.include <bsd.port.mk>
