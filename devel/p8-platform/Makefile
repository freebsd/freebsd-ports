PORTNAME=	p8-platform
PORTVERSION=	2.1.0.1
PORTREVISION=	2
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	Platform support library used by libCEC and binary add-ons for Kodi

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
