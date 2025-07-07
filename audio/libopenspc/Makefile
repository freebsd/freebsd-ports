PORTNAME=	libopenspc
PORTVERSION=	0.3.99a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://rainbow-runner.nl/freebsd/ \
		LOCAL/kwm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for playing SPC (SNES audio) files

BUILD_DEPENDS=	nasm:devel/nasm

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386
LDFLAGS_i386=	-Wl,-znotext

PLIST_FILES=	include/openspc.h lib/libopenspc.a \
		lib/libopenspc.so lib/libopenspc.so.0 lib/libopenspc.so.0.0.3

.include <bsd.port.mk>
