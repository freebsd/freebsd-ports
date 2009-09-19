# New ports collection makefile for:	lzmautils-devel
# Date created:		09 Dec 2008
# Whom:			David Naylor <dragonsa@highveldmail.co.za>
#
# $FreeBSD$
#

PORTNAME=	lzmautils
DISTVERSION=	4.999.8
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/xz/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMESUFFIX=	-devel
DISTNAME=	xz-${DISTVERSION}beta

MAINTAINER=	dragonsa@highveldmail.co.za
COMMENT=	LZMA compression and decompression tools

CONFLICTS=	lzma-[0-9]* lzmautils-4.[0-3]* lzmautils-[0-3]* lzmalib-[0-9]*

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack

CONFIGURE_ARGS+=	--disable-static --disable-nls  # No translations apparent

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--disable-threads
.endif

MAN1=		lzdiff.1 lzgrep.1 lzmore.1
MLINKS=		lzdiff.1 lzcmp.1 \
		lzgrep.1 lzegrep.1 \
		lzgrep.1 lzfgrep.1 \
		lzmore.1 lzless.1

.include <bsd.port.mk>
