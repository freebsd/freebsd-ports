# New ports collection makefile for:	esdl
# Date Created:				2 January 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esdl
PORTVERSION=	0.91.1129
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	esdl
DISTNAME=	esdl-${PORTVERSION}.src

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes

.include <bsd.port.mk>
