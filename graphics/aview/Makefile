# New ports collection Makefile for:	aview
# Date created:		Dec 18 1997
# Whom:			frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	aview
PORTVERSION=	1.3.0.r1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aa-project
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics viewer for viewing netpbm format on console or X using aalib

RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x=no

MAN1=		asciiview.1 aview.1

post-patch:
	@${REINPLACE_CMD} -e 's|/bash|/sh|g' ${WRKSRC}/asciiview
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.mk>
