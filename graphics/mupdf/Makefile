# New ports collection makefile for:	mupdf
# Date created:		2009-08-07
# Whom:			Martin Dieringer <martin.dieringer@gmx.de>
#
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	0.8.165
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://www.mupdf.com/download/
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	lichray@gmail.com
COMMENT=	Lightweight PDF viewer and toolkit

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		jbig2dec.0:${PORTSDIR}/graphics/jbig2dec \
		openjpeg.2:${PORTSDIR}/graphics/openjpeg

USE_GMAKE=	yes
MAKE_ARGS+=	build=release prefix=${PREFIX} verbose=1 mandir=${PREFIX}/man
USE_XORG=	x11 xext
USE_GNOME=	pkgconfig
MAN1=		mupdf.1 mu_pdfclean.1 mu_pdfdraw.1 mu_pdfshow.1

MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	SCROLL	"Build with scroll hacks" on \

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
CFLAGS+=	-mfpmath=sse
.endif

.if defined(WITH_SCROLL)
EXTRA_PATCHES+=	${FILESDIR}/scroll_hack-apps_pdfapp.c
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} \
		-e 's#\(PDF_APPS :=.*/\)#\1mu_#' \
		-e 's#\(XPS_APPS :=.*/\)#\1mu_#' \
		-e 's#\(MUPDF) :.*/\)#\1mu_#' \
		-e 's#\(OUT)/\).*: apps/#\1mu_%.o : apps/#' \
		-e '/install:/,/^$$/ { /-d/d; }' \
		-e '/install.*bindir)$$/s/install/$$(BSD_INSTALL_PROGRAM)/' \
		-e '/install.*libdir)$$/s/install/$$(BSD_INSTALL_LIB)/' \
		-e '/install.*incdir)$$/s/install/$$(BSD_INSTALL_DATA)/' \
		-e '/install.*man1$$/s/install/$$(BSD_INSTALL_MAN)/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/-O2//' \
		-e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makerules

pre-install:	.SILENT
	${FIND} ${WRKSRC} -name pdf\*.1 -exec ${SH} -c 'mv {} $$(dirname {})/mu_$$(basename {})' \;

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
