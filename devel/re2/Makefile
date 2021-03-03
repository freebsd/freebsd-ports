# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	re2
DISTVERSION=	20210202
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast C++ regex library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes

GH_ACCOUNT=	google
GH_TAGNAME=	${DISTVERSION:C|(....)(..)(..)|\1-\2-\3|}
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	RE2_BUILD_TESTING

post-install:
	@${CP} -a ${INSTALL_WRKSRC}/libre2.so.* ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
