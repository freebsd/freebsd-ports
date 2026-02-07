PORTNAME=	libdbusmenu-lxqt
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITE=	LXQT/${PORTNAME}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Qt6 implementation of the DBusMenu protocol
WWW=		https://github.com/lxqt/libdbusmenu-lxqt

LICENSE=	LGPL20

USES=		compiler:c++17-lang cmake lxqt:2 qt:6 tar:xz
USE_LDCONFIG=	yes
USE_QT=		base

OPTIONS_DEFINE=		DOXYGEN
OPTIONS_SUB=		YES
DOXYGEN_DESC=		Build documentation (requires doxygen)
DOXYGEN_CMAKE_BOOL=	WITH_DOC
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.  if defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	DOXYGEN
.  endif

post-patch:
	@${REINPLACE_CMD} -e '/add_subdirectory(tests)/ d' \
			  -e '/add_subdirectory(tools)/ d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
