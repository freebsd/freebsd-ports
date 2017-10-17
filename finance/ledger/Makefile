# Created by: wcarey
# $FreeBSD$

PORTNAME=	ledger
PORTVERSION=	3.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	finance

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/include/utf8.h:devel/utf8cpp
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libboost_system.so:devel/boost-libs

BROKEN_powerpc64=	fails to link: ibledger.so.3: undefined reference to boost::match_results

USE_GITHUB=	yes

USE_LDCONFIG=	yes
USES=		cmake compiler:c++11-lib libedit

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man \
		-DCMAKE_INCLUDE_PATH=${LOCALBASE}/include

.include <bsd.port.mk>
