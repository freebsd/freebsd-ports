PORTNAME=	eglexternalplatform
DISTVERSION=	1.2.1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EGL External Platform interface
WWW=		https://github.com/NVIDIA/eglexternalplatform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA
NO_BUILD=	yes
PLIST_FILES=	include/EGL/${PORTNAME}.h \
		include/EGL/${PORTNAME}version.h \
		libdata/pkgconfig/${PORTNAME}.pc

pre-install:
	@${REINPLACE_CMD} 's,/include,/include/EGL,' ${WRKSRC}/_build/meson-private/${PORTNAME}.pc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/EGL
	${INSTALL_DATA} ${WRKSRC}/interface/* ${STAGEDIR}${PREFIX}/include/EGL
	${INSTALL_DATA} ${WRKSRC}/_build/meson-private/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
