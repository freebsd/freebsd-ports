# Created by: gahr
# $FreeBSD$

PORTNAME=	csoap
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel net www
MASTER_SITES=	SF/${PORTNAME}/libsoap/${PORTVERSION}
DISTNAME=	libsoap-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Client/server SOAP library written in pure C

GNU_CONFIGURE=	yes
USES=		pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libsoap-${PORTVERSION}

.include <bsd.port.mk>
