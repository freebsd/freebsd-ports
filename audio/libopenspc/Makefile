# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopenspc
PORTVERSION=	0.3.99a
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kwm

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for playing SPC (SNES audio) files

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

PLIST_FILES=	include/openspc.h lib/libopenspc.a lib/libopenspc.la \
		lib/libopenspc.so lib/libopenspc.so.0 \

.include <bsd.port.mk>
