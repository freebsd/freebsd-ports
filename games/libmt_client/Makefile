# New ports collection makefile for:	libmt_client
# Date created:		Sun 7 mar 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		libmt_client
PORTVERSION=		0.1.98
PORTREVISION=	1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	maitretarot/${PORTNAME}.pkg/${PORTVERSION}

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Client-side library of MaitreTarot, a Tarot card game

LIB_DEPENDS=		maitretarot.0:${PORTSDIR}/games/libmaitretarot

USE_BZIP2=		yes
USE_INC_LIBTOOL_VER=	13
USE_GNOME=		glib20 libxml2 lthack
INSTALLS_SHLIB=		yes

.include <bsd.port.mk>
