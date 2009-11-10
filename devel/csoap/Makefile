# New ports collection Makefile for:	csoap
# Date created:				10 November 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	csoap
PORTVERSION=	1.1.0
CATEGORIES=	devel net www
MASTER_SITES=	SF/${PORTNAME}/libsoap/${PORTVERSION}
DISTNAME=	libsoap-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A client/server SOAP library written in pure C

GNU_CONFIGURE=	yes
USE_GNOME=	libxml2 gnomehack
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libsoap-${PORTVERSION}

.include <bsd.port.mk>
