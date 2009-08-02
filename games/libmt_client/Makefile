# New ports collection makefile for:	libmt_client
# Date created:		Sun 7 mar 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		libmt_client
PORTVERSION=		0.1.98
PORTREVISION=	4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	maitretarot

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Client-side library of MaitreTarot, a Tarot card game

LIB_DEPENDS=		maitretarot.0:${PORTSDIR}/games/libmaitretarot

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		glib20 libxml2 lthack
USE_LDCONFIG=		yes

.include <bsd.port.mk>
