# Created by: gno@yahoo-inc.com
# $FreeBSD$

PORTNAME=	json-c
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JSON (JavaScript Object Notation) implementation in C

LICENSE=	MIT

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig libtool
USE_GITHUB=	yes

GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	20140410

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	install-strip

CONFLICTS=	cocaine-core-[0-9]*

.include <bsd.port.mk>
