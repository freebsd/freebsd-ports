# New ports collection makefile for:	esdl
# Date Created:				2 January 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esdl
PORTVERSION=	0.93.0909
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for accessing SDL and OpenGL through Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_MESA=	yes
USE_GMAKE=	yes
USE_SDL=	yes
ALL_TARGET=	target
PLIST_SUB=	VERSION="${PORTVERSION}"

post-install:
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
