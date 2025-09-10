PORTNAME=	feh
PORTVERSION=	3.11.2
CATEGORIES=	graphics
MASTER_SITES=	https://feh.finalrewind.org/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Image viewer that utilizes Imlib2
WWW=		https://feh.finalrewind.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libpng.so:graphics/png
TEST_DEPENDS=	p5-Test-Command>=0:devel/p5-Test-Command

USES=		cpe desktop-file-utils gmake localbase:ldflags tar:bzip2 xorg
CPE_VENDOR=	feh_project
USE_XORG=	x11 xinerama xt

MAKE_ENV+=	LDFLAGS="${LDFLAGS}" \
		verscmp=0
TEST_TARGET=	test

OPTIONS_DEFINE=		CURL DCRAW DOCS EXAMPLES EXIF XINERAMA
OPTIONS_DEFAULT=	CURL EXIF XINERAMA
OPTIONS_SUB=		yes

DCRAW_DESC=	Use dcraw to display raw file previews
EXIF_DESC=	Support EXIF tags

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MAKE_ENV=		curl=1
CURL_MAKE_ENV_OFF=	curl=0
DCRAW_RUN_DEPENDS=	dcraw:graphics/dcraw
EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_MAKE_ENV=		exif=1
EXIF_MAKE_ENV_OFF=	exif=0
XINERAMA_MAKE_ENV=	xinerama=1
XINERAMA_MAKE_ENV_OFF=	xinerama=0

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|install-doc||' \
		${WRKSRC}/Makefile

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e 's|install-examples||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/feh

.include <bsd.port.mk>
