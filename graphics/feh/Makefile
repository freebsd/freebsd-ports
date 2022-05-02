# Created by: Jeremy Norris <ishmael127@home.com>

PORTNAME=	feh
PORTVERSION=	3.5
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/ \
		LOCAL/uqs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer that utilizes Imlib2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libpng.so:graphics/png

USES=		compiler:c++11-lang cpe desktop-file-utils gmake localbase:ldflags \
		tar:bzip2 xorg
USE_XORG=	x11 xt xinerama
CPE_VENDOR=	feh_project

MAKE_ENV+=	LDFLAGS="${LDFLAGS}" verscmp=0

OPTIONS_DEFINE=	CURL DCRAW DOCS EXAMPLES EXIF XINERAMA
EXIF_DESC=	Support EXIF tags
DCRAW_DESC=	Use dcraw to display raw file previews
OPTIONS_DEFAULT=CURL EXIF XINERAMA
OPTIONS_SUB=	yes

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_MAKE_ENV=		exif=1
EXIF_MAKE_ENV_OFF=	exif=0

XINERAMA_MAKE_ENV=	xinerama=1
XINERAMA_MAKE_ENV_OFF=	xinerama=0

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MAKE_ENV=		curl=1
CURL_MAKE_ENV_OFF=	curl=0

DCRAW_RUN_DEPENDS=	dcraw:graphics/dcraw

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|install-doc||' \
		${WRKSRC}/Makefile

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e 's|install-examples||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/feh

.include <bsd.port.mk>
