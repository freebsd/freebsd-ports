# $FreeBSD$

PORTNAME=	ignition-msgs
DISTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Protobuf messages and functions for robot applications

LICENSE=	APACHE20

BUILD_DEPENDS=	ignition-cmake==2:devel/ignition-cmake \
		ignition-tools>0:devel/ignition-tools
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libignition-math6.so:math/ignition-math

USES=		compiler:c++11-lang cmake:outsource
USE_RUBY=	yes
USE_LDCONFIG=	yes

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-msgs
BB_COMMIT=	4a1cbcabff7d

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_SUB=	MSGS_IGN_VER=msgs${DISTVERSION:R:R}

.include <bsd.port.mk>
