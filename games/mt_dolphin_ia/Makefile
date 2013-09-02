# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=		mt_dolphin_ia
PORTVERSION=		0.1.98
PORTREVISION=	3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	maitretarot

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		A basic AI for MaitreTarot, a Tarot card game

LIB_DEPENDS=		mt_client.0:${PORTSDIR}/games/libmt_client

USES=			pkgconfig
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		glib20 libxml2

CONFIGURE_ARGS=		--with-libmt_client=${LOCALBASE}	\
			--with-libmaitretarot=${LOCALBASE}

PLIST_FILES=		bin/mt_dolphin_ia

.include <bsd.port.mk>
