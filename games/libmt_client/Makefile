PORTNAME=	libmt_client
PORTVERSION=	0.1.98
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/maitretarot

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Client-side library of MaitreTarot, a Tarot card game
WWW=		https://www.nongnu.org/maitretarot/

LICENSE=	GPLv2

LIB_DEPENDS=	libmaitretarot.so:games/libmaitretarot

GNU_CONFIGURE=	yes
USES=		gnome libtool pkgconfig tar:bzip2
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
