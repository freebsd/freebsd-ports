PORTNAME=	atl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for the creation and manipulation of lists of name/value pairs
WWW=		https://github.com/GTkorvo/atl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	GTkorvo

SHEBANG_FILES=	atl-config.in

# tests as of 2.4.1: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
