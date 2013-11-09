# Created by: gno@yahoo-inc.com
# $FreeBSD$

PORTNAME=	json-c
PORTVERSION=	0.11
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/archive/

MAINTAINER=	gno@yahoo-inc.com
COMMENT=	JSON (JavaScript Object Notation) implementation in C

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
USE_GITHUB=	yes
USE_ZIP=	yes
MAKE_JOBS_UNSAFE=	yes

GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	20130402

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}

CONFLICTS=	cocaine-core-[0-9]*

.include <bsd.port.mk>
