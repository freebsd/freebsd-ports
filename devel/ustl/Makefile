# ex:ts=8
# Ports collection makefile for:	uSTL
# Date created:			Dec 26, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ustl
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Codespace-frugal STL implementation

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,${LOCALBASE}/bin/bash," ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|SIZE_MAX|UINT_MAX|" ${WRKSRC}/memblock.h
	@${REINPLACE_CMD} -e "s|-Werror||" ${WRKSRC}/Common.mk.in

.include <bsd.port.mk>
