# New ports collection makefile for:	xpdf
# Version required:     0.90
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $FreeBSD$
#

DISTNAME=       xpdf-0.90
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} ftp://ftp.foolabs.com/pub/xpdf/  \
		ftp://ftp.duke.edu/pub/X11/contrib/applications/
MASTER_SITE_SUBDIR=support/xpdf
EXTRACT_SUFX=	.tgz

.if !defined(PACKAGE_BUILDING)
PATCH_SITES=	http://www.fefe.de/
PATCHFILES=	xpdf-0.90-fefe-diff.gz
PATCH_DIST_STRIP= -p1
.endif

MAINTAINER=	chuckr@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		t1.9:${PORTSDIR}/devel/t1lib

.if !defined(PACKAGE_BUILDING)
RESTRICTED=     "Contains cryptography"
.endif
USE_XLIB=	yes
USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-gzip --enable-japanese		\
		--with-t1-library=${LOCALBASE}/lib	\
		--with-t1-includes=${LOCALBASE}/include	\
		--with-t1x-library=${LOCALBASE}/lib	\
		--with-t1x-includes=${LOCALBASE}/include
.if defined(A4)
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

MAN1=		pdfimages.1 \
		pdfinfo.1 \
		pdftopbm.1 \
		pdftops.1 \
		pdftotext.1 \
		xpdf.1

.include <bsd.port.mk>
