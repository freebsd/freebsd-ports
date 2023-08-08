PORTNAME=	p8-platform
PORTVERSION=	2.1.0.1
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	3
CATEGORIES=	devel

PATCH_SITES=	https://github.com/Pulse-Eight/platform/commit/
PATCHFILES=	a7cd0d5780ed80a4e70480d1650749f29e8a1fb2.patch:-p1 # https://github.com/Pulse-Eight/platform/pull/45

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	Platform support library used by libCEC and binary add-ons for Kodi
WWW=		https://github.com/Pulse-Eight/platform

LICENSE=	GPLv2+

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	Pulse-Eight
GH_PROJECT=	platform

USE_LDCONFIG=	yes
CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON

post-patch:
	@${REINPLACE_CMD} -e '/SOVERSION/ s|\.0||' \
		-e 's|$${CMAKE_INSTALL_LIBDIR_NOARCH}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
