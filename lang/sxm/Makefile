# ex:ts=8
# New ports collection makefile for:	sxm
# Date created:		Jan 8, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sxm
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.malgil.com/sxm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another implementation of Scheme

USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	all image Formlist

MAN1=		sxm.1 sxi.1

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g ; \
		s,^CC,#CC,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
