# New ports collection makefile for:	xpdf
# Version required:     0.80
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $Id: Makefile,v 1.19 1998/12/09 10:44:36 vanilla Exp $
#

DISTNAME=       xpdf-0.80
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/  \
		ftp://ftp.duke.edu/pub/X11/contrib/applications/  \
		ftp://ftp.cdrom.com/pub/tex/ctan/support/xpdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chuckr@glue.umd.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gzip --enable-japanese
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

MAN1=		pdfimages.1 \
		pdfinfo.1 \
		pdftopbm.1 \
		pdftops.1 \
		pdftotext.1 \
		xpdf.1

.include <bsd.port.mk>
