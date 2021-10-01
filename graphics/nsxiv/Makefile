PORTNAME=	nsxiv
DISTVERSIONPREFIX=	v
DISTVERSION=	27.1-20
DISTVERSIONSUFFIX=	-g065562d
CATEGORIES=	graphics
PATCH_SITES=	https://github.com/0mp/nsxiv/commit/
PATCHFILES=	d44674845ac41621cdaf69f6898b81fac435233f.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple X image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libfontconfig.so:x11-fonts/fontconfig \
		libgif.so:graphics/giflib \
		libImlib2.so:graphics/imlib2 \
		libinotify.so:devel/libinotify

USES=		desktop-file-utils gmake localbase:ldflags pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	x11 xft

MAKE_ARGS=	PREFIX=${PREFIX}
MAKE_ENV=	OPTIONAL_LIBS=-linotify

INSTALL_TARGET=	install-all

OPTIONS_DEFINE=	DOCS

# These examples files belong to the project's documentation. Let's leave them
# in the doc directory for simplicity.
PORTDOCS=	examples/image-info \
		examples/key-handler

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
