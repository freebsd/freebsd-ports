# New ports collection makefile for:	xpdf
# Version required:     0.80
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $Id: Makefile,v 1.15 1998/09/17 00:32:43 asami Exp $
#

DISTNAME=       xpdf-0.80
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chuckr@glue.umd.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gzip
USE_X_PREFIX=	yes
MAN1=		pdfimages.1 \
		pdfinfo.1 \
		pdftopbm.1 \
		pdftops.1 \
		pdftotext.1 \
		xpdf.1

.include <bsd.port.mk>
