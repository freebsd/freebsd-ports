PORTNAME=	nsxiv
DISTVERSIONPREFIX=	v
DISTVERSION=	28
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple X image viewer
WWW=		https://github.com/nsxiv/nsxiv

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libfontconfig.so:x11-fonts/fontconfig \
		libgif.so:graphics/giflib \
		libImlib2.so:graphics/imlib2 \
		libinotify.so:devel/libinotify \
		libwebp.so:graphics/webp \
		libwebpdemux.so:graphics/webp

USES=		desktop-file-utils gmake localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	x11 xft

MAKE_ARGS=	MANPREFIX=${PREFIX}/share/man
MAKE_ENV=	EGPREFIX=${EXAMPLESDIR} LDLIBS=-linotify

INSTALL_TARGET=	install-all

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
