# Created by: ijliao
# $FreeBSD$

PORTNAME=	openzz
PORTVERSION=	1.0.4.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.0.4-4
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreted dynamic parser

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-Wno-return-type

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s/cfree/free/g" ${WRKSRC}/src/list.c
	@${REINPLACE_CMD} -e "s/argv\[\]/*argv/" ${WRKSRC}/src/zzbind.h

.include <bsd.port.mk>
