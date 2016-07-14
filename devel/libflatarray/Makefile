# Created by: Kurt Kanzenbach <kurt@kmk-computers.de>
# $FreeBSD$

PORTNAME=	libflatarray
PORTVERSION=	0.2.0
CATEGORIES=	devel science
MASTER_SITES=	http://www.libgeodecomp.org/archive/

MAINTAINER=	kurt@kmk-computers.de
COMMENT=	Struct of arrays library with object oriented interface for C++

LICENSE=	BSL

BUILD_DEPENDS=	boost-libs>=1.48:${PORTSDIR}/devel/boost-libs

USES=		cmake:outsource

CMAKE_ARGS+=	-DWITH_CUDA:BOOL=FALSE

.include <bsd.port.mk>
