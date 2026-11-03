PORTNAME=	oaml
PORTVERSION=	1.3.4
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open Adaptive Music Library
WWW=		https://oamldev.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN=		Fails to build with CMake 4
DEPRECATED=	Abandoned upstream, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis

USE_GITHUB=	yes
GH_ACCOUNT=	oamldev

USES=		cmake compiler:c++11-lang
CMAKE_ARGS=	-DENABLE_UNITYPLUGIN:BOOL=OFF

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS SOXR
OPTIONS_DEFAULT=	SOXR
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CMAKE_BOOL=	ENABLE_SOXR

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
