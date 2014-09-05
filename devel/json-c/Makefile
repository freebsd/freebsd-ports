# Created by: gno@yahoo-inc.com
# $FreeBSD$

PORTNAME=	json-c
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON (JavaScript Object Notation) implementation in C

LICENSE=	MIT

CONFLICTS_INSTALL=	cocaine-core-[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	2a03577
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}-20140410

.include <bsd.port.mk>
