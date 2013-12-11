# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	mymoon
DISTVERSION=	1.2a
PORTREVISION=	5
CATEGORIES=	astro
MASTER_SITES=	http://makemebad.net/geek/codes/${PORTNAME}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	krion

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show latitude and longitude of the moon

LIB_DEPENDS=	libnova.so:${PORTSDIR}/astro/libnova

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USES=		gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mymoon

.include <bsd.port.mk>
