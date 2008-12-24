# New ports collection makefile for:	lzmautils-devel
# Date created:		09 Dec 2008
# Whom:			David Naylor <dragonsa@highveldmail.co.za>
#
# $FreeBSD$
#

PORTNAME=	lzmautils
DISTVERSION=	4.999.3alpha
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/lzma/
PKGNAMESUFFIX?=	-devel
DISTNAME=	lzma-${DISTVERSION}

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	LZMA compression and decompression tools

CONFLICTS=	lzma-[0-9]* lzmautils-4.[0-3]* lzmautils-[0-3]*

USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack

MAN1=		lzdiff.1 lzgrep.1 lzmore.1
MLINKS=		lzma.1 unlzma.1 \
		lzma.1 lzcat.1 \
		lzdiff.1 lzcmp.1 \
		lzgrep.1 lzegrep.1 \
		lzgrep.1 lzfgrep.1 \
		lzmore.1 lzless.1			

.include <bsd.port.mk>
