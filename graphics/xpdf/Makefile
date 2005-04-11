# New ports collection makefile for:	xpdf
# Date created:         02 Feb 1996
# Whom:                 chuckr@glue.umd.edu
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.00
PORTREVISION=	6
CATEGORIES=	graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/xpdf

.if defined(WANT_ANTIKICK)
PATCH_SITES=	http://www.cs.cmu.edu/~dst/Adobe/Gallery/XPDF/anti-kick/
PATCHFILES=	anti.diff
#.else
#PATCH_SITES=	http://vzzbx.xs4all.nl/files/ \
#		http://www.cs.cmu.edu/~dst/Adobe/Gallery/
#PATCHFILES=	xpdf-ro-remove.patch
.endif
PATCH_DIST_STRIP= -p1
PATCH_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN}
PATCH_SITE_SUBDIR=	support/xpdf
PATCHFILES=	xpdf-2.01-patch1

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Display PDF files, and convert them to other formats

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/n021003l.pfb:${PORTSDIR}/print/gsfonts

USE_X_PREFIX=	yes
USE_MOTIF=	yes

USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
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
.if defined(WANT_ANTIKICK)
CONFIGURE_ARGS+=	--enable-antikick
.endif

MAN1=		pdffonts.1 \
		pdfimages.1 \
		pdfinfo.1 \
		pdftoppm.1 \
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

.if ${ARCH} == "amd64"
CFLAGS+=	-static
.endif
