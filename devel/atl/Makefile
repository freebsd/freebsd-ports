PORTNAME=	atl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1-43
DISTVERSIONSUFFIX=	-g7286dd1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for the creation and manipulation of lists of name/value pairs
WWW=		https://github.com/GTkorvo/atl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	GTkorvo

SHEBANG_FILES=	atl-config.in

.include <bsd.port.mk>
