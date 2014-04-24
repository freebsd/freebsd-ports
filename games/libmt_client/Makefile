# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	libmt_client
PORTVERSION=	0.1.98
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	maitretarot

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Client-side library of MaitreTarot, a Tarot card game

LICENSE=	GPLv2

LIB_DEPENDS=	libmaitretarot.so:${PORTSDIR}/games/libmaitretarot

USES=		pkgconfig tar:bzip2
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 libxml2 lthack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
