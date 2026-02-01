PORTNAME=	mymoon
DISTVERSION=	1.2a
PORTREVISION=	5
CATEGORIES=	astro
MASTER_SITES=	http://makemebad.net/geek/codes/${PORTNAME}/ \
		LOCAL/krion

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show latitude and longitude of the moon

BROKEN=		tries to download a tar file from a nonworking website
DEPRECATED=	mastersite disappeared
EXPIRATION_DATE=	2026-05-01

LIB_DEPENDS=	libnova.so:astro/libnova

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USES=		gmake ncurses

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mymoon

.include <bsd.port.mk>
