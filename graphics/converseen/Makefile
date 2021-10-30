PORTNAME=	converseen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.9.2
CATEGORIES=	graphics

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use graphics conversion utility

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang magick:6 qt:5 tar:bzip2
USE_QT=		core gui network widgets \
		buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	Faster3ck
GH_PROJECT=	Converseen

post-patch:
	@${REINPLACE_CMD} -e '/^install(FILES converseen.appdata.xml/s|/usr|$${CMAKE_INSTALL_PREFIX}|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>
