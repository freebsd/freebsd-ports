# New ports collection makefile for:	openyahtzee
# Date created:		04 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openyahtzee
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Open%20Yahtzee/Open%20Yahtzee%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-featured classic dice game Yahtzee

USE_BZIP2=	yes
USE_WX=		2.8+
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
