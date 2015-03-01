# Created by: ijliao
# $FreeBSD$

PORTNAME=	openzz
PORTVERSION=	1.0.4.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.0.4-4
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreted dynamic parser

LICENSE=	LGPL21 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-return-type
INSTALL_TARGET=	install-strip
USES=		libtool readline
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/cfree/free/g" ${WRKSRC}/src/list.c
	@${REINPLACE_CMD} -e "s/argv\[\]/*argv/" ${WRKSRC}/src/zzbind.h

.include <bsd.port.mk>
