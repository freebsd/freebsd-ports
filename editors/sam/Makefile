# New ports collection makefile for:    sam
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	sam
PORTVERSION=	4.3
CATEGORIES=	editors plan9
MASTER_SITES=	ftp://ftp.cs.usyd.edu.au/matty/unicode/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.msg.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A unix version of Rob Pike's editor for plan9

EXTRACT_CMD=		${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	| ${SH}

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

MAN1=		sam.1
MAN3=		add.3 balloc.3 bitblt.3 cachechars.3 event.3 frame.3 \
		graphics.3 rgbpix.3 rune.3
MAN4=		font.4 keyboard.4 utf.4
MAN6=		bitmap.6 regexp.6

.include <bsd.port.mk>
