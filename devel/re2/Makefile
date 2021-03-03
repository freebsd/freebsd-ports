# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	re2
PORTVERSION=	20210202
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast C++ regex library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake pathfix

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" SED_INPLACE="${SED} -i ''" prefix=${PREFIX}
USE_LDCONFIG=	yes

PATHFIX_MAKEFILEIN=	Makefile

GH_ACCOUNT=	google
GH_TAGNAME=	${PORTVERSION:C|(....)(..)(..)|\1-\2-\3|}
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libre2.so

.include <bsd.port.mk>
