# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	exhaust
PORTVERSION=	1.9.2
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/pihlaja/exhaust/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Redcode simulator easy to embed into applications

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
