PORTNAME=	qiv
PORTVERSION=	3.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://spiegl.de/qiv/download/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Small, fast GDK/Imlib2 image viewer
WWW=		https://spiegl.de/qiv/

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		liblcms2.so:graphics/lcms2 \
		libexif.so:graphics/libexif \
		libtiff.so:graphics/tiff

USES=		gmake gnome jpeg pkgconfig tar:tgz xorg
USE_GNOME=	cairo gdkpixbuf gtk30

PLIST_FILES=	bin/qiv share/man/man1/qiv.1.gz
USE_XORG+=	x11 xext

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qiv ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/qiv.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
