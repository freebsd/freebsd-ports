# New ports collection makefile for:	esdl
# Date Created:				2 January 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esdl
PORTVERSION=	0.93.0131
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	esdl
DISTNAME=	esdl-${PORTVERSION}.src
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for accessing SDL and OpenGL through Erlang

BROKEN=		"Does not install"

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	target
USE_GMAKE=	yes

.include <bsd.port.mk>
