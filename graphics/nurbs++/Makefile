# New ports collection makefile for:	nurbs++
# Date created:				14 May 2000
# Whom:					R Joseph Wright <rjoseph@mammalia.org>
#
# $FreeBSD$
#

PORTNAME=	nurbs++
PORTVERSION=	3.0.11
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/libnurbs/nurbs%2B%2B/nurbs%2B%2B-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A C++ library for representing curves or surfaces

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="s/x/x/"
USE_LDCONFIG=	yes

MAN1=	nurbs++-config.1

.include <bsd.port.mk>
