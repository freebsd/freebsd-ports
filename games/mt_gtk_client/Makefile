# New ports collection makefile for:	mt_gtk_client
# Date created:		Sun 7 mar 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		mt_gtk_client
PORTVERSION=		0.1.98
PORTREVISION=	6
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	maitretarot

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		GTK+ client for MaitreTarot, a Tarot card game

LIB_DEPENDS=		mt_client.0:${PORTSDIR}/games/libmt_client
RUN_DEPENDS=		${LOCALBASE}/share/cardpics/images/78.png:${PORTSDIR}/games/cardpics

USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GETTEXT=		yes
USE_GNOME=		glib20 gtk20 libxml2

.if !defined(WITHOUT_SERVER)
RUN_DEPENDS+=		${LOCALBASE}/bin/maitretarot_server:${PORTSDIR}/games/maitretarot
.endif
.if !defined(WITHOUT_IA)
RUN_DEPENDS+=		${LOCALBASE}/bin/mt_dolphin_ia:${PORTSDIR}/games/mt_dolphin_ia
.endif

.include <bsd.port.mk>
