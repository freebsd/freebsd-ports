# $FreeBSD$

PORTNAME=	pachi
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	12.40
PORTREVISION=	3
CATEGORIES=	games
PKGNAMESUFFIX=	-game-engine

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fairly strong Go/Baduk/Weiqi playing program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcaffe.so:graphics/caffe \
		libglog.so:devel/glog

USES=		gmake localbase shebangfix
SHEBANG_FILES=	genbuild spudfrog
USE_GITHUB=	yes
GH_ACCOUNT=	pasky

BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
