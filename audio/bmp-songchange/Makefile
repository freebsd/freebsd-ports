# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmp-songchange
PORTVERSION=	0.0.2
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	BERLIOS/bmp-plugins

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Beep Media Player do-this-on-song-change plugin

EXPIRATION_DATE=	2013-12-24
DEPRECATED=	No public distfiles available anymore

LICENSE=	GPLv2

LIB_DEPENDS=	libbeep.so:${PORTSDIR}/multimedia/beep-media-player

USES=		pkgconfig

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/bmp/General/libsong_change.so

post-patch:
	${REINPLACE_CMD} -e "s,echo aout, echo elf," ${WRKSRC}/configure

.include <bsd.port.mk>
