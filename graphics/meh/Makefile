PORTNAME=	meh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-27
DISTVERSIONSUFFIX=	-g69f653a
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple image viewer using raw XLib convert from ImageMagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png

USES=		gmake jpeg localbase magick:7,run xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jhawthorn
USE_XORG=	x11 xext

ALL_TARGET=	${PORTNAME}

LIBS+=		-lgif -ljpeg -lpng -lX11 -lXext

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
