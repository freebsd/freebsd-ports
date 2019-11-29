# $FreeBSD$

PORTNAME=	dmlc-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-105
DISTVERSIONSUFFIX=	-g32d9fe7
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common library for scalable and portable distributed machine learning

LICENSE=	APACHE20

USES=		compiler:openmp cmake
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
