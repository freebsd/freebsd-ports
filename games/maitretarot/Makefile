# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=		maitretarot
PORTVERSION=		0.1.98
PORTREVISION=	3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Server side of MaitreTarot, a Tarot card game

LIB_DEPENDS=		maitretarot.0:${PORTSDIR}/games/libmaitretarot

USES=			pkgconfig
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		glib20 libxml2

CONFIGURE_ARGS=		--with-default-config-file=${PREFIX}/etc/maitretarotrc.xml

PLIST_FILES=		bin/maitretarot_server

NO_STAGE=	yes
.include <bsd.port.mk>
