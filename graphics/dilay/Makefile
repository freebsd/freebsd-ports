# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	dilay
PORTVERSION=	1.5.0
CATEGORIES=	graphics

MAINTAINER=	yuri@rawbw.com
COMMENT=	3D sculpting application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USE_GITHUB=	yes
GH_ACCOUNT=	abau

USES=		compiler:c++14-lang gmake qmake
USE_CXXSTD=	c++14
USE_GL=		gl
USE_QT5=	core gui opengl widgets xml buildtools_build

# Workaround for: Parallel build fails (https://github.com/abau/dilay/issues/19)
MAKE_JOBS_UNSAFE=yes
# Workaround for: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=210327
QMAKE_ARGS+=	QMAKE_CXXFLAGS_CXX11=

PLIST_FILES=	bin/dilay

BROKEN_FreeBSD_9=	does not build on FreeBSD < 10: "unordered_set" not found

.include <bsd.port.mk>
