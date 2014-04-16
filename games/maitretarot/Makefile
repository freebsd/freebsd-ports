# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	maitretarot
PORTVERSION=	0.1.98
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Server side of MaitreTarot, a Tarot card game

LICENSE=	GPLv2

LIB_DEPENDS=	libmaitretarot.so:${PORTSDIR}/games/libmaitretarot

USES=		pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 libxml2

CONFIGURE_ARGS=	--with-default-config-file=${PREFIX}/etc/maitretarotrc.xml

PLIST_FILES=	bin/maitretarot_server

.include <bsd.port.mk>
