# New ports collection makefile for:	xpdf
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	1.00
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/  \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/xpdf

MAINTAINER=	DougB@FreeBSD.org

LIB_DEPENDS=	t1.4:${PORTSDIR}/devel/t1lib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_FREETYPE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-gzip --enable-opi		\
		--with-t1-library=${LOCALBASE}/lib	\
		--with-t1-includes=${LOCALBASE}/include	\
		--with-freetype-library=${LOCALBASE}/lib \
		--with-freetype-includes=${LOCALBASE}/include/freetype
.if defined(A4)
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

MAN1=		pdffonts.1 \
		pdfimages.1 \
		pdfinfo.1 \
		pdftopbm.1 \
		pdftops.1 \
		pdftotext.1 \
		xpdf.1
MAN5=		xpdfrc.5

.include <bsd.port.mk>
