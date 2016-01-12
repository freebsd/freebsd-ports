# Created by: ijliao
# $FreeBSD$

PORTNAME=	openzz
DISTVERSION=	1.0.4-4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.0.4-4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreted dynamic parser

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-return-type
USES=		libtool readline
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/cfree/free/g" ${WRKSRC}/src/list.c
	@${REINPLACE_CMD} -e "s/argv\[\]/*argv/" ${WRKSRC}/src/zzbind.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
