# New ports collection makefile for:	xpdf
# Version required:     0.80
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $FreeBSD$
#

DISTNAME=       xpdf-0.80
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} ftp://ftp.foolabs.com/pub/xpdf/  \
		ftp://ftp.duke.edu/pub/X11/contrib/applications/  \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=support/xpdf
EXTRACT_SUFX=	.tgz

.if defined(USA_RESIDENT) && !defined(PACKAGE_BUILDING)
PATCH_SITES=	ftp://ftp.sci.usq.edu.au/pub/linux/xpdf/
PATCHFILES=	xpdf-0.80-decrypt.patch
PATCH_DIST_ARGS=-p0 -E -d ${WRKDIR} --quiet
.endif

MAINTAINER=	chuckr@glue.umd.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

.if defined(USA_RESIDENT) && !defined(PACKAGE_BUILDING)
RESTRICTED=     "Contains cryptography"
.endif
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
