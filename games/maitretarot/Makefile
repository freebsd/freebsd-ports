PORTNAME=	maitretarot
PORTVERSION=	0.1.98
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Server side of MaitreTarot, a Tarot card game
WWW=		https://www.nongnu.org/maitretarot/

LICENSE=	GPLv2

LIB_DEPENDS=	libmaitretarot.so:games/libmaitretarot

USES=		gnome pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 libxml2

CONFIGURE_ARGS=	--with-default-config-file=${PREFIX}/etc/maitretarotrc.xml

PLIST_FILES=	bin/maitretarot_server

.include <bsd.port.mk>
