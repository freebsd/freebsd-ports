PORTNAME=	converseen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0.3
CATEGORIES=	graphics

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use graphics conversion utility
WWW=		https://converseen.sourceforge.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

FLAVORS=	qt5 qt6

USES=		cmake compiler:c++11-lang gl magick:7 qt:5 tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	Faster3ck
GH_PROJECT=	Converseen
USE_GL=		gl
USE_QT=		core gui network widgets \
		buildtools:build linguisttools:build qmake:build

.if ${FLAVOR:U} == qt6
PKGNAMESUFFIX=	-${FLAVOR}
USES:=		${USES:S/qt:5/qt:6/}
USE_QT=		base tools:build
CMAKE_ARGS=	-DUSE_QT6=yes
CONFLICTS_INSTALL=	${PORTNAME}
.else
CONFLICTS_INSTALL=	${PORTNAME}-qt6
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>
