# New ports collection makefile for:    sam
# Version required:     4.3
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.6 1998/11/28 09:07:17 asami Exp $
#

DISTNAME=	sam
PKGNAME=	sam-4.3
CATEGORIES=	editors plan9
MASTER_SITES=	ftp://ftp.ecf.toronto.edu/pub/plan9/matty/
EXTRACT_SUFX=	.msg.gz

MAINTAINER=	erich@FreeBSD.org

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

MAN1=		sam.1
MAN3=		add.3 balloc.3 bitblt.3 cachechars.3 event.3 frame.3 \
		graphics.3 rgbpix.3 rune.3
MAN4=		font.4 keyboard.4 utf.4
MAN6=		bitmap.6 regexp.6
MANCOMPRESSED=	yes

.include <bsd.port.mk>
