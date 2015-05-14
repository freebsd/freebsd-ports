# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		cpp-netlib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=		0.11.1
DISTVERSIONSUFFIX=	-final
PORTREVISION=		1
CATEGORIES=		devel

MAINTAINER=		zi@FreeBSD.org
COMMENT=		Cross-platform, standards compliant networking library

LICENSE=		BSL

BUILD_DEPENDS=		boost-libs>0:${PORTSDIR}/devel/boost-libs

USES=			cmake:outsource
CMAKE_ARGS+=		-DCPP-NETLIB_BUILD_EXAMPLES=OFF
USE_GITHUB=		yes

.include <bsd.port.mk>
