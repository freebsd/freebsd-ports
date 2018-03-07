# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	dilay
DISTVERSION=	1.7.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	3D sculpting application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		compiler:c++14-lang gmake qmake
USE_GITHUB=	yes
GH_ACCOUNT=	abau
USE_CXXSTD=	c++14
USE_GL=		gl
USE_QT5=	core gui opengl widgets xml buildtools_build

MAKE_JOBS_UNSAFE=	yes  # Workaround for: https://github.com/abau/dilay/issues/19 parallel build fails (still a problem despite having been closed)

PLIST_FILES=	bin/dilay \
		share/applications/dilay.desktop
.for sz in 16 32 48 256
PLIST_FILES+=	share/icons/hicolor/${sz}x${sz}/apps/dilay.png
.endfor

.include <bsd.port.mk>
