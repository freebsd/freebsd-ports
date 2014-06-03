# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unshield
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	archivers
MASTER_SITES=	SF/synce/Unshield/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extract data from InstallShield CAB files

LICENSE=	MIT

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunshield.so.0.0.0

.include <bsd.port.mk>
