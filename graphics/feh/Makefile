# Created by: Jeremy Norris <ishmael127@home.com>
# $FreeBSD$

PORTNAME=	feh
PORTVERSION=	2.23
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

USE_XORG=	x11 xt xinerama
USES=		cpe desktop-file-utils gmake perl5 shebangfix tar:bzip2
CPE_VENDOR=	daniel_friesel
USE_PERL5=	run

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=	CAM DOCS EXAMPLES EXIF
CAM_DESC=	Install feh-cam and related tools
EXIF_DESC=	Support EXIF tags
OPTIONS_DEFAULT=CAM EXIF
OPTIONS_SUB=	yes

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAM}
MAKE_ENV+=	cam=1
SHEBANG_FILES=	${WRKSRC}/cam/feh-cam
.endif

.if ${PORT_OPTIONS:MEXIF}
MAKE_ENV+=	exif=1
.endif

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|install-doc||' \
		${WRKSRC}/Makefile

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e 's|install-examples||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/feh

.include <bsd.port.mk>
