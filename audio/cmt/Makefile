# New ports collection Makefile for:   cmt
# Date created:                        11 May 2002
# Whom:                                Tilman Linneweh <freebsdports@arved.de
#
# $FreeBSD$

PORTNAME=	cmt
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	${PORTNAME}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsdports@arved.de

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
ALL_TARGET=	targets

pre-patch:
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

do-install:
	@${INSTALL_DATA} ${WRKSRC}/../plugins/cmt.so ${LOCALBASE}/lib/ladspa/

.include <bsd.port.mk>
