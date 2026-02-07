PORTNAME=	mcpp
DISTVERSION=	2.7.2.1
CATEGORIES=	devel

MAINTAINER=	kmatsui@t3.rim.or.jp
COMMENT=	Alternative C/C++ preprocessor
WWW=		https://mcpp.sourceforge.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool
CPE_VENDOR=	mcpp_project
USE_GITHUB=	yes
GH_ACCOUNT=	museoa
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mcpplib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
