# New ports collection makefile for:    freeze
# Version required:     2.5
# Date created:         20 Jul 1996
# Whom:                 lukin@okbmei.msk.su
#
# $Id: Makefile,v 1.1 1996/07/20 00:17:21 lukin Exp $
#

DISTNAME=       freeze-2.5
CATEGORIES+=	archivers
MASTER_SITES=	ftp://lupin.csv.warwick.ac.uk/pub/compression/

MAINTAINER=     lukin@okbmei.msk.su

GNU_CONFIGURE=	yes
ALL_TARGET=	prog

post-install:
.if !defined(NOMANCOMPRESS)
.for man in freeze melt unfreeze fcat statist
	gzip -9nf ${PREFIX}/man/man1/${man}.1
.endfor
.endif

.include <bsd.port.mk>
