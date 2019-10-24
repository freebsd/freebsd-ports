# Created by: tenser@spitfire.ecsel.psu.edu
# $FreeBSD$

PORTNAME=	bsvc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.6
CATEGORIES=     emulators tk

MAINTAINER=	cross@gajendra.net
COMMENT=	Extensible hardware simulation framework with MC68K support

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

USES=		tk gmake

USE_GITHUB=	yes
GH_ACCOUNT=	BSVC
USE_CSTD=	c11
USE_CXXSTD=	c++11

WRKSRC_SUBDIR=	src
MAKEFILE=	Makefile.BSD
MAKE_ARGS+=	WISH=wish${TK_VER}

.include <bsd.port.mk>
