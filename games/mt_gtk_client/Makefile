# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=		mt_gtk_client
PORTVERSION=		0.1.98
PORTREVISION=		12
CATEGORIES=		games
MASTER_SITES=		SAVANNAH/maitretarot

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		GTK+ client for MaitreTarot, a Tarot card game

LICENSE=		GPLv2

LIB_DEPENDS=		libmt_client.so:games/libmt_client
RUN_DEPENDS=		${LOCALBASE}/share/cardpics/images/78.png:games/cardpics

GNU_CONFIGURE=		yes
USES=			gettext pkgconfig tar:bzip2
USE_GNOME=		glib20 gtk20 libxml2

.if !defined(WITHOUT_SERVER)
RUN_DEPENDS+=		${LOCALBASE}/bin/maitretarot_server:games/maitretarot
.endif
.if !defined(WITHOUT_IA)
RUN_DEPENDS+=		${LOCALBASE}/bin/mt_dolphin_ia:games/mt_dolphin_ia
.endif

.include <bsd.port.mk>
