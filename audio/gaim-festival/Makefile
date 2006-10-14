# New ports collection makefile for:	gaim-festival
# Date created:		2 Jan 2005
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/audio/gaim-festival/Makefile,v 1.1 2006/10/04 22:31:17 ahze Exp $

PORTNAME=	festival
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	festival-gaim
PKGNAMEPREFIX=	gaim-
DISTNAME=	festival-gaim-1.00

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Festival speech support for Gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival \
		gaim:${PORTSDIR}/net-im/gaim

USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15:env
MAKE_ENV=	LOCALBASE=${LOCALBASE}

PLIST_FILES=	lib/gaim/festival.so

NOMAN=

do-configure:

.include <bsd.port.mk>
