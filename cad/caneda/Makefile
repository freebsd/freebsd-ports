# $FreeBSD$

PORTNAME=	caneda
DISTVERSION=	0.3.1
CATEGORIES=	cad
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EDA software suite focused on ease of use and portability

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqwt6.so:x11-toolkits/qwt6

USES=		cmake compiler:c++11-lang desktop-file-utils qt:5 \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	Caneda
GH_PROJECT=	Caneda
USE_QT=		core gui printsupport svg widgets buildtools_build linguisttools_build qmake_build

CMAKE_ARGS=	-DQWT_INCLUDE_DIR=${LOCALBASE}/include/qt5/qwt6 -DQWT_LIBRARY=${LOCALBASE}/lib/qt5/libqwt6.so

.include <bsd.port.mk>
