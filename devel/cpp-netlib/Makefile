# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		cpp-netlib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=		0.11.2
DISTVERSIONSUFFIX=	-final
CATEGORIES=		devel

MAINTAINER=		zi@FreeBSD.org
COMMENT=		Cross-platform, standards compliant networking library

LICENSE=		BSL
LICENSE_FILE=		${WRKSRC}/LICENSE_1_0.txt

BUILD_DEPENDS=		boost-libs>0:${PORTSDIR}/devel/boost-libs

USES=			cmake:outsource
CMAKE_ARGS+=		-DCPP-NETLIB_BUILD_EXAMPLES=OFF
USE_GITHUB=		yes

.include <bsd.port.mk>
