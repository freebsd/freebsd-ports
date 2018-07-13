# Created by: Jeremy Norris <ishmael127@home.com>
# $FreeBSD$

PORTNAME=	feh
PORTVERSION=	2.27
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/ \
		LOCAL/uqs

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Image viewer that utilizes Imlib2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libImlib2.so:graphics/imlib2 \
		libpng.so:graphics/png

USES=		compiler:c++11-lang cpe desktop-file-utils gmake localbase:ldflags \
		perl5 shebangfix tar:bzip2
SHEBANG_FILES=	cam/feh-cam
USE_XORG=	x11 xt xinerama
USE_PERL5=	run
CPE_VENDOR=	daniel_friesel

MAKE_ENV+=	LDFLAGS="${LDFLAGS}" verscmp=0

OPTIONS_DEFINE=	CAM DOCS EXAMPLES EXIF
CAM_DESC=	Install feh-cam and related tools
EXIF_DESC=	Support EXIF tags
OPTIONS_DEFAULT=CAM EXIF
OPTIONS_SUB=	yes

CAM_MAKE_ENV=	cam=1

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_MAKE_ENV=	exif=1

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|install-doc||' \
		${WRKSRC}/Makefile

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e 's|install-examples||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/feh

.include <bsd.port.mk>
