# ex:ts=8
# Ports collection makefile for:	swftools
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swftools
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.swftools.org/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	SWF manipulation and generation utilities

LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		fftw3:${PORTSDIR}/math/fftw3 \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

LICENSE=	GPLv2

OPTIONS=	LAME "LAME MP3 audio encoder support" off \
		PDF "PDFlib support" off

USE_GNOME=	pkgconfig
USE_GL=		glut
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_zzip_zzip_file_open=no

MAKE_JOBS_SAFE=	yes

MAN1=		as3compile.1 font2swf.1 gif2swf.1 jpeg2swf.1 pdf2swf.1 \
		png2swf.1 swfbbox.1 swfc.1 swfcombine.1 swfdump.1 \
		swfextract.1 swfrender.1 swfstrings.1 wav2swf.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.else
#CONFIGURE_ARGS+=	--disable-lame
CONFIGURE_ENV+=	ac_cv_lib_mp3lame_lame_init=no
.endif

.if defined(WITH_PDF)
LIB_DEPENDS+=	pdf.8:${PORTSDIR}/print/pdflib
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

.include <bsd.port.post.mk>
