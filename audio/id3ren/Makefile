# New ports collection makefile for: id3ren
# Date created:         28 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	id3ren
PORTVERSION=	0.97a
CATEGORIES=	audio
MASTER_SITES=	http://adis.on.ca/pub/Linux/cd-tools/ \
		http://cbothamy.free.fr/projects/id3ren/
DISTNAME=	id3ren97a

MAINTAINER=	jonny@jonny.eng.br

USE_ZIP=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/id3ren/src

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/id3ren.c ${WRKSRC}/misc.c

.include <bsd.port.mk>
