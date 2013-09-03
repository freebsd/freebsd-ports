# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmp-songchange
PORTVERSION=	0.0.2
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	BERLIOS/bmp-plugins

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Beep Media Player do-this-on-song-change plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USES=		pkgconfig

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/bmp/General/libsong_change.so

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,echo aout, echo elf," ${WRKSRC}/configure

.include <bsd.port.post.mk>
