# New ports collection makefile for:	xpdf
# Version required:     0.7a
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp $
#

DISTNAME=       xpdf-0.7a
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.aimnet.com/pub/users/derekn/xpdf/

MAINTAINER=	chuckr@glue.umd.edu

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gzip
USE_X_PREFIX=	yes
MAN1=		xpdf.1 pdftops.1 pdftotext.1

.include <bsd.port.mk>
