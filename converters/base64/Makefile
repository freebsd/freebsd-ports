# New ports collection makefile for:	groach
# Date created:				29 Oct 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	base64
PORTVERSION=	0.1
CATEGORIES=	converters
MASTER_SITES=	http://www.codecenter.com/base64/
DISTNAME=	b64

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	clean all
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin

.include <bsd.port.mk>
