# ex:ts=8
# New ports collection makefile for:	sxm
# Date created:		Jan 8, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sxm
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	http://www.malgil.com/sxm/

MAINTAINER=	ijliao@FreeBSD.org

USE_GMAKE=	yes
ALL_TARGET=	all image Formlist

MAN1=		sxm.1 sxi.1

post-extract:
	@${PERL} -pi -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
