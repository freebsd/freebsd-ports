# New ports collection makefile for:	xpdf
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	2.03
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/xpdf

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Display PDF files, and convert them to other formats

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		freetype.9:${PORTSDIR}/print/freetype2

USE_X_PREFIX=	yes
USE_MOTIF=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gzip --enable-opi --with-x \
		--with-t1-library="${LOCALBASE}/lib" \
		--with-t1-includes="${LOCALBASE}/include" \
		--with-freetype2-library="${LOCALBASE}/lib" \
		--with-freetype2-includes="${LOCALBASE}/include/freetype2"
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

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE CHANGES INSTALL README misc/hello.pdf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
