# New ports collection makefile for:	nurbs++
# Date created:				14 May 2000
# Whom:					R Joseph Wright <rjoseph@mammalia.org>
#
# $FreeBSD$
#

PORTNAME=	nurbs++
PORTVERSION=	3.0.10
CATEGORIES=	graphics
MASTER_SITES=	http://yukon.genie.uottawa.ca/~lavoie/software/nurbs/

MAINTAINER= 	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/nurbs/nurbs.cc ${WRKSRC}/nurbs/nurbsS.cc

.include <bsd.port.mk>
