# New ports collection makefile for:	lzmautils
# Date created:		2008-04-19
# Whom:			naddy
#
# $FreeBSD$
#

PORTNAME=	lzmautils
PORTVERSION=	4.32.7
CATEGORIES=	archivers
MASTER_SITES=	http://tukaani.org/lzma/
DISTNAME=	lzma-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	LZMA compression and decompression tools

CONFLICTS=	lzma-[0-9]*

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		lzdiff.1 lzgrep.1 lzma.1 lzmadec.1 lzmainfo.1 lzmore.1

MLINKS=		lzma.1 unlzma.1 \
		lzma.1 lzcat.1 \
		lzdiff.1 lzcmp.1 \
		lzgrep.1 lzegrep.1 \
		lzgrep.1 lzfgrep.1 \
		lzmore.1 lzless.1

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
