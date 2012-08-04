# ex:ts=8
# Ports collection makefile for:	swftools
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swftools
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.swftools.org/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SWF manipulation and generation utilities

LICENSE=	GPLv2

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		gif.5:${PORTSDIR}/graphics/giflib \
		fftw3:${PORTSDIR}/math/fftw3 \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	LAME PDF

USE_GL=		glut
USE_GMAKE=	yes
USE_PKGCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_zzip_zzip_file_open=no

MAKE_JOBS_SAFE=	yes

MAN1=		as3compile.1 font2swf.1 gif2swf.1 jpeg2swf.1 pdf2swf.1 \
		png2swf.1 swfbbox.1 swfc.1 swfcombine.1 swfdump.1 \
		swfextract.1 swfrender.1 swfstrings.1 wav2swf.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.else
#CONFIGURE_ARGS+=	--disable-lame
CONFIGURE_ENV+=	ac_cv_lib_mp3lame_lame_init=no
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=	pdf.6:${PORTSDIR}/print/pdflib
PLIST_SUB+=	PDF=""
MAN1+=		pdf2pdf.1
.else
CONFIGURE_ENV+=	ac_cv_lib_pdf_PDF_open_file=no
PLIST_SUB+=	PDF="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -O | |g ; \
		 s|/usr/include/fontconfig|${LOCALBASE}/include/fontconfig|g ; \
		 s|/usr/local/include|${LOCALBASE}/include|g ; \
		 s|/usr/local/lib|${LOCALBASE}/lib|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/python/d ; \
		 /avi2swf/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
