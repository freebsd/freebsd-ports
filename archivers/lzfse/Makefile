# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lzfse
PORTVERSION=	20160707
CATEGORIES=	archivers

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Lempel-Ziv style data compression algorithm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	lzfse
GH_TAGNAME=	4591228

USES=	gmake
MAKE_ARGS+=	INSTALL_PREFIX="${STAGEDIR}${PREFIX}"

.include <bsd.port.mk>
