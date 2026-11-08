PORTNAME=	imlib2_loaders
DISTVERSION=	1.12.7
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	SF/enlightenment/imlib2-src/${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2
WWW=		https://docs.enlightenment.org/api/imlib2/html/

LICENSE=	GPLv2 imlib2
LICENSE_COMB=	multi
LICENSE_NAME_imlib2=	imlib2 license
LICENSE_FILE_imlib2=	${WRKSRC}/COPYING
LICENSE_PERMS_imlib2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	imlib2>0:graphics/imlib2

USES=		libtool localbase pathfix pkgconfig tar:xz xorg
USE_XORG=	x11 xext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-xcf

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/imlib2/loaders/xcf.so

.include <bsd.port.mk>
