# New ports collection makefile for:	gaim-festival
# Date created:		2 Jan 2005
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	festival
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	festival-gaim
PKGNAMEPREFIX=	gaim-
DISTNAME=	festival-gaim-1.00

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Festival speech support for Gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net/gaim
RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival \
		gaim:${PORTSDIR}/net/gaim

USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WANT_LIBTOOL_VER=15
MAKE_ENV=	LOCALBASE=${LOCALBASE}

PLIST_FILES=	lib/gaim/festival.so

NOMAN=

do-configure:

.include <bsd.port.mk>
