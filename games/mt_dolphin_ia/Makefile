# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=		mt_dolphin_ia
PORTVERSION=		0.1.98
PORTREVISION=		5
CATEGORIES=		games
MASTER_SITES=		SAVANNAH/maitretarot

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Basic AI for MaitreTarot, a Tarot card game

LICENSE=		GPLv2

LIB_DEPENDS=		libmt_client.so:games/libmt_client

USES=			gnome pkgconfig tar:bzip2
GNU_CONFIGURE=		yes
USE_GNOME=		glib20 libxml2

CONFIGURE_ARGS=		--with-libmt_client=${LOCALBASE}	\
			--with-libmaitretarot=${LOCALBASE}

PLIST_FILES=		bin/mt_dolphin_ia

.include <bsd.port.mk>
