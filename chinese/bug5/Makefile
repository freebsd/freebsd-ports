# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bug5
PORTVERSION=	1.18
CATEGORIES=	chinese converters

MAINTAINER=	buganini@gmail.com
COMMENT=	Big5/GBK <-> UTF-8 translating layer in terminal

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

LIB_DEPENDS=	libbsdconv.so:converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini

MAKE_ARGS=	PREFIX=${PREFIX}

PLIST_FILES=	bin/bug5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bug5

.include <bsd.port.mk>
