# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gscan2pdf
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Config-General>=2.40:devel/p5-Config-General \
		p5-Glib2>=1.210:devel/p5-Glib2 \
		p5-Goo-Canvas>0:devel/p5-Goo-Canvas \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Log-Log4perl>0:devel/p5-Log-Log4perl \
		p5-Readonly>0:devel/p5-Readonly \
		ImageMagick>0:graphics/ImageMagick \
		p5-Sane>=0.05:graphics/p5-Sane \
		p5-Set-IntSpan>=1.10:math/p5-Set-IntSpan \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		bash:shells/bash \
		p5-PDF-API2>0.57:textproc/p5-PDF-API2 \
		p5-Gtk2>=1.090:x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-Simple-List>0:x11-toolkits/p5-Gtk2-Ex-Simple-List \
		p5-Gtk2-ImageView>0:x11-toolkits/p5-Gtk2-ImageView
RUN_DEPENDS:=	p5-Archive-Tar>0:archivers/p5-Archive-Tar \
		p5-Proc-ProcessTable>0:devel/p5-Proc-ProcessTable \
		xdg-open:devel/xdg-utils \
		cjb2:graphics/djvulibre \
		scanimage:graphics/sane-backends \
		scanadf:graphics/sane-frontends \
		unpaper:graphics/unpaper \
		p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-Gtk2-Ex-PodViewer>0.17:x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-Filesys-Df>0.92:sysutils/p5-Filesys-Df \
		p5-Data-UUID>=1.220:devel/p5-Data-UUID \
		${BUILD_DEPENDS}

NO_ARCH=	yes

USES=		gettext gmake perl5 tar:xz
USE_GNOME=	gtk20 librsvg2
USE_PERL5=	configure

OPTIONS_MULTI=		OCR
OPTIONS_MULTI_OCR=	CUNEIFORM GOCR OCROPUS TESSERACT
OPTIONS_DEFAULT=	GOCR

CUNEIFORM_DESC=		Multi-language OCR system
CUNEIFORM_RUN_DEPENDS=	cuneiform:graphics/cuneiform
GOCR_DESC=		OCR program developed under GPL
GOCR_RUN_DEPENDS=	gocr:graphics/gocr
OCR_DESC=		Optical Character Recognition
OCROPUS_DESC=		Document analysis and OCR system
OCROPUS_RUN_DEPENDS=	ocropus:graphics/ocropus
TESSERACT_DESC=		OCR engine developed at Google
TESSERACT_RUN_DEPENDS=	tesseract:graphics/tesseract

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$sharedir/man|$$prefixdir/man| ; \
		 s|1p|1|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
