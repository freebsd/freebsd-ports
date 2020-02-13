# $FreeBSD$

PORTNAME=	eglexternalplatform
DISTVERSION=	1.1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	EGL External Platform interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA
NO_BUILD=	yes
PLIST_FILES=	include/EGL/${PORTNAME}.h \
		include/EGL/${PORTNAME}version.h \
		libdata/pkgconfig/${PORTNAME}.pc

post-patch:
	@${REINPLACE_CMD} 's,/usr,${PREFIX},' ${WRKSRC}/eglexternalplatform.pc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/EGL
	${INSTALL_DATA} ${WRKSRC}/interface/* ${STAGEDIR}${PREFIX}/include/EGL
	${INSTALL_DATA} ${WRKSRC}/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
