# New ports collection makefile for:	xpdf
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $FreeBSD$
#

PORTNAME=       xpdf
PORTVERSION=	0.91
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} ftp://ftp.foolabs.com/pub/xpdf/  \
		ftp://ftp.duke.edu/pub/X11/contrib/applications/
MASTER_SITE_SUBDIR=support/xpdf
EXTRACT_SUFX=	.tgz

MAINTAINER=	chuckr@freebsd.org

LIB_DEPENDS=	t1x.1:${PORTSDIR}/devel/t1lib \
		ttf.4:${PORTSDIR}/print/freetype

### crypto
#.if !defined(PACKAGE_BUILDING)
#RESTRICTED=     "Contains cryptography"
#.endif
USE_XLIB=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-gzip --enable-opi		\
		--enable-japanese --enable-chinese	\
		--with-t1-library=${LOCALBASE}/lib	\
		--with-t1-includes=${LOCALBASE}/include	\
		--with-t1x-library=${LOCALBASE}/lib	\
		--with-t1x-includes=${LOCALBASE}/include \
		--with-freetype-library=${LOCALBASE}/lib \
		--with-freetype-includes=${LOCALBASE}/include
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
