# New ports collection makefile for:    xfractint
# Version required:     3.00
# Date created:         7 Sept 1995
# Whom:                 cacho@mexicano.gdl.iteso.mx
#
# $Id$
#

DISTNAME=       xfract300
PKGNAME=	xfractint-3.00
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/sprite/
EXTRACT_SUFX=	.shar.Z

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/xfractint.1
.endif

.include <bsd.port.mk>
