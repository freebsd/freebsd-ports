# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sxm
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.malgil.com/sxm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another implementation of Scheme

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_GMAKE=	yes
ALL_TARGET=	all image Formlist

MAN1=		sxm.1 sxi.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g ; \
		s,^CC,#CC,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
