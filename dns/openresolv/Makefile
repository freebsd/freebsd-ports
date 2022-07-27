PORTNAME=	openresolv
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://roy.marples.name/downloads/openresolv/

MAINTAINER=	roy@marples.name
COMMENT=	Resolvconf compatible framework for managing resolv.conf

USES=		cpe tar:xz
CPE_VENDOR=	${PORTNAME}_project

GNU_CONFIGURE=	yes

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

.include <bsd.port.mk>
