# New ports collection makefile for:	gnomoku
# Date created:				21 May 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomoku
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Gomoku game for GNOME Desktop

LIB_DEPENDS=	gnomemm-1.2.10:${PORTSDIR}/x11-toolkits/gnome--

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
