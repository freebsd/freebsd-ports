# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gscan2pdf
PORTVERSION=	2.3.0
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Config-General>=2.40:devel/p5-Config-General \
		p5-Glib2>=1.210:devel/p5-Glib2 \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Log-Log4perl>0:devel/p5-Log-Log4perl \
		p5-Readonly>0:devel/p5-Readonly \
		ImageMagick6>0:graphics/ImageMagick6 \
		p5-Image-Sane>=0.14:graphics/p5-Image-Sane \
		p5-Set-IntSpan>=1.10:math/p5-Set-IntSpan \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		bash:shells/bash \
		p5-PDF-API2>0.57:textproc/p5-PDF-API2 \
		p5-Gtk3>=0.028:x11-toolkits/p5-Gtk3 \
		p5-Gtk3-SimpleList>=0.17:x11-toolkits/p5-Gtk3-SimpleList \
		p5-Goo-Canvas2>=0.06:devel/p5-Goo-Canvas2
RUN_DEPENDS:=	p5-Proc-ProcessTable>0:devel/p5-Proc-ProcessTable \
		xdg-open:devel/xdg-utils \
		cjb2:graphics/djvulibre \
		scanimage:graphics/sane-backends \
		scanadf:graphics/sane-frontends \
		unpaper:graphics/unpaper \
		ImageMagick6>0:graphics/ImageMagick6 \
		p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-Filesys-Df>0.92:sysutils/p5-Filesys-Df \
		p5-Data-UUID>=1.220:devel/p5-Data-UUID \
		p5-Date-Calc>=6.4:devel/p5-Date-Calc \
		p5-Config-General>=2.40:devel/p5-Config-General \
		p5-Glib2>=1.210:devel/p5-Glib2 \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Log-Log4perl>0:devel/p5-Log-Log4perl \
		p5-Readonly>0:devel/p5-Readonly \
		p5-Image-Sane>=0.14:graphics/p5-Image-Sane \
		p5-Set-IntSpan>=1.10:math/p5-Set-IntSpan \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		p5-PDF-API2>0.57:textproc/p5-PDF-API2 \
		p5-Gtk3>=0.028:x11-toolkits/p5-Gtk3 \
		p5-Gtk3-SimpleList>=0.17:x11-toolkits/p5-Gtk3-SimpleList \
		p5-Goo-Canvas2>=0.06:devel/p5-Goo-Canvas2

USES=		gettext gmake gnome perl5 tar:xz

NO_ARCH=	yes

USE_GNOME=	gtk30 librsvg2
USE_PERL5=	configure

OPTIONS_MULTI=		OCR
OPTIONS_MULTI_OCR=	GOCR TESSERACT
OPTIONS_DEFAULT=	GOCR

GOCR_DESC=		OCR program developed under GPL
GOCR_RUN_DEPENDS=	gocr:graphics/gocr
OCR_DESC=		Optical Character Recognition
TESSERACT_DESC=		OCR engine developed at Google
TESSERACT_RUN_DEPENDS=	tesseract:graphics/tesseract

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$sharedir/man|$$prefixdir/man| ; \
		 s|1p|1|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
