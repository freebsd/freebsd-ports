# Created by: ijliao
# $FreeBSD$

PORTNAME=	swftools
PORTVERSION=	0.9.2
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://www.swftools.org/ \
		http://www.c-s.li/ports/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SWF manipulation and generation utilities

LICENSE=	GPLv2

LIB_DEPENDS=	libt1.so:devel/t1lib \
		libgif.so:graphics/giflib \
		libfftw3.so:math/fftw3 \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake pkgconfig jpeg gl
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_zzip_zzip_file_open=no

LMAN1=		as3compile.1 font2swf.1 gif2swf.1 jpeg2swf.1 pdf2swf.1 \
		png2swf.1 swfbbox.1 swfc.1 swfcombine.1 swfdump.1 \
		swfextract.1 swfrender.1 swfstrings.1 wav2swf.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BINFILES=	as3compile font2swf gif2swf jpeg2swf pdf2swf png2swf \
		swfbbox swfc swfcombine swfdump swfextract swfrender \
		swfstrings wav2swf

OPTIONS_DEFINE=	LAME PDF
OPTIONS_SUB=	yes
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
PDF_LIB_DEPENDS=	libpdf.so:print/pdflib

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MLAME}
CONFIGURE_ENV+=	ac_cv_lib_mp3lame_lame_init=no
.endif

.if ${PORT_OPTIONS:MPDF}
LMAN1+=		pdf2pdf.1
BINFILES+=	pdf2pdf
.else
CONFIGURE_ENV+=	ac_cv_lib_pdf_PDF_open_file=no
.endif

post-patch:
	${REINPLACE_CMD} -e 's| -O | |g ; \
		 s|/usr/include/fontconfig|${LOCALBASE}/include/fontconfig|g ; \
		 s|/usr/local/include|${LOCALBASE}/include|g ; \
		 s|/usr/local/lib|${LOCALBASE}/lib|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/python/d ; \
		 /avi2swf/d' ${WRKSRC}/Makefile.in

do-install:
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for i in ${LMAN1}
	${INSTALL_DATA} ${WRKSRC}/src/${i} ${STAGEDIR}${PREFIX}/man/man1/
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/swfs
	${INSTALL_DATA} ${WRKSRC}/swfs/*.swf ${STAGEDIR}${DATADIR}/swfs/
	${LN} -s simple_viewer.swf ${STAGEDIR}${DATADIR}/swfs/default_viewer.swf
	${LN} -s tessel_loader.swf ${STAGEDIR}${DATADIR}/swfs/default_loader.swf

.include <bsd.port.mk>
