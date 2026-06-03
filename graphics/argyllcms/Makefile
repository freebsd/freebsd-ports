PORTNAME=	argyllcms
PORTVERSION=	3.5.0
CATEGORIES=	graphics
MASTER_SITES=	https://www.argyllcms.com/
DISTNAME=	Argyll_V${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICC compatible color management system
WWW=		https://www.argyllcms.com/

LICENSE=	AGPLv3

BUILD_DEPENDS=	jam:devel/jam
LIB_DEPENDS=	libjpeg.so:graphics/jpeg-turbo \
		libmxml.so:textproc/mxml \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libyajl.so:devel/yajl

EXCLUDE=	zlib tiff png jpeg usb xml yajl
EXTRACT_AFTER_ARGS=${EXCLUDE:C|^(.*)$|-x */\1/*|}
WRKSRC=		${WRKDIR}/Argyll_V${PORTVERSION}
MAKE_ENV+=	CCFLAGS="${CFLAGS} -DUNIX -Wno-dangling-else"

USES=		compiler:c11 cpe jpeg ssl xorg zip
USE_XORG=	x11 xau xdmcp xext xinerama xrandr xscrnsaver xxf86vm

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g'	\
	    ${WRKSRC}/Jamtop ${WRKSRC}/Jambase

do-build:
	@cd ${WRKSRC} && ${MAKE_ENV} jam -dx -q -fJambase -j${MAKE_JOBS_NUMBER}

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${MAKE_ENV} \
		REFSUBDIR=share/argyll/ref \
		jam -dx -q -fJambase -j${MAKE_JOBS_NUMBER} install
	${MV} ${STAGEDIR}${PREFIX}/bin/License.txt \
		${STAGEDIR}${PREFIX}/share/argyll/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*


.include <bsd.port.mk>
