# New ports collection makefile for:	bmp-wma
# Date created:		2004-07-16
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	bmp-wma
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.nixp.ru/pub/files/ \
		http://bmpwma.younggods.net/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	WMA input plugin for beep-media-player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

PLIST_FILES=	lib/bmp/Input/libwma.so

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-x86
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not build on amd64 or ia64 (tries to link static library against shared)"
.endif

.include <bsd.port.post.mk>
