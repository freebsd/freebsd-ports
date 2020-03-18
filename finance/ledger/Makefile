# Created by: wcarey
# $FreeBSD$

PORTNAME=	ledger
PORTVERSION=	3.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	18
CATEGORIES=	finance

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	c18a55f9ef99.patch:-p1

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_FreeBSD_11_powerpc64=	fails to link on powerpc64 elfv1: ibledger.so.3: undefined reference to boost::match_results
BROKEN_FreeBSD_12_powerpc64=	fails to link on powerpc64 elfv1: ibledger.so.3: undefined reference to boost::match_results

BUILD_DEPENDS=	${LOCALBASE}/include/utf8.h:devel/utf8cpp
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lib libedit
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man \
		-DCMAKE_INCLUDE_PATH=${LOCALBASE}/include

.include <bsd.port.mk>
