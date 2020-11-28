# $FreeBSD$

PORTNAME=	picoc
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	lang devel

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Very small C interpreter for scripting

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	zsaleeba
GH_TAGNAME= 4555e84

USES=		gmake readline

PLIST_FILES=	bin/picoc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${STAGEDIR}${PREFIX}/bin/picoc

.include <bsd.port.mk>
