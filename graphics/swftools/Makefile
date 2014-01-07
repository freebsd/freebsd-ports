# Created by: ijliao
# $FreeBSD$

PORTNAME=	swftools
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.swftools.org/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SWF manipulation and generation utilities

LICENSE=	GPLv2

LIB_DEPENDS=	libt1.so:${PORTSDIR}/devel/t1lib \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

NO_STAGE=	yes

USES=		pkgconfig gmake
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_zzip_zzip_file_open=no

MAN1=		as3compile.1 font2swf.1 gif2swf.1 jpeg2swf.1 pdf2swf.1 \
		png2swf.1 swfbbox.1 swfc.1 swfcombine.1 swfdump.1 \
		swfextract.1 swfrender.1 swfstrings.1 wav2swf.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	LAME PDF
OPTIONS_SUB=	yes
LAME_LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame
PDF_LIB_DEPENDS=	libpdf.so:${PORTSDIR}/print/pdflib

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MLAME}
CONFIGURE_ENV+=	ac_cv_lib_mp3lame_lame_init=no
.endif

.if ${PORT_OPTIONS:MPDF}
MAN1+=		pdf2pdf.1
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

.include <bsd.port.mk>
