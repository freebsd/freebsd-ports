PORTNAME=	5compat
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 module that contains unsupported Qt 5 APIs

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl \
		qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative shadertools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
