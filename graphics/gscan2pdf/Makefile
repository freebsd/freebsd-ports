PORTNAME=	gscan2pdf
PORTVERSION=	2.13.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Produce PDF from scanned documents
WWW=		https://sourceforge.net/projects/gscan2pdf/

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Config-General>=2.40:devel/p5-Config-General \
		p5-Glib>=1.210:devel/p5-Glib \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Log-Log4perl>0:devel/p5-Log-Log4perl \
		p5-Readonly>0:devel/p5-Readonly \
		p5-Image-Sane>=0.14:graphics/p5-Image-Sane \
		p5-Set-IntSpan>=1.10:math/p5-Set-IntSpan \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		bash:shells/bash \
		p5-PDF-Builder>0:textproc/p5-PDF-Builder \
		p5-Gtk3>=0.028:x11-toolkits/p5-Gtk3 \
		p5-Gtk3-ImageView>0:x11-toolkits/p5-Gtk3-ImageView \
		p5-Gtk3-SimpleList>=0.17:x11-toolkits/p5-Gtk3-SimpleList \
		p5-Goo-Canvas2>=0.06:devel/p5-Goo-Canvas2
RUN_DEPENDS:=	p5-Proc-ProcessTable>0:devel/p5-Proc-ProcessTable \
		xdg-open:devel/xdg-utils \
		cjb2:graphics/djvulibre \
		scanimage:graphics/sane-backends \
		unpaper:graphics/unpaper \
		p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-Filesys-Df>0.92:sysutils/p5-Filesys-Df \
		p5-Data-UUID>=1.220:devel/p5-Data-UUID \
		p5-Date-Calc>=6.4:devel/p5-Date-Calc \
		p5-Config-General>=2.40:devel/p5-Config-General \
		p5-Glib>=1.210:devel/p5-Glib \
		p5-Locale-Codes>0:misc/p5-Locale-Codes \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Log-Log4perl>0:devel/p5-Log-Log4perl \
		p5-Readonly>0:devel/p5-Readonly \
		p5-Graphics-TIFF>0:graphics/p5-Graphics-TIFF \
		p5-Image-PNG-Libpng>0:graphics/p5-Image-PNG-Libpng \
		p5-Image-Sane>=0.14:graphics/p5-Image-Sane \
		p5-Set-IntSpan>=1.10:math/p5-Set-IntSpan \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		p5-PDF-Builder>0:textproc/p5-PDF-Builder \
		p5-Gtk3>=0.028:x11-toolkits/p5-Gtk3 \
		p5-Gtk3-ImageView>0:x11-toolkits/p5-Gtk3-ImageView \
		p5-Gtk3-SimpleList>=0.17:x11-toolkits/p5-Gtk3-SimpleList \
		p5-Goo-Canvas2>=0.06:devel/p5-Goo-Canvas2 \
		p5-Gtk2-Ex-PodViewer>0:x11-toolkits/p5-Gtk2-Ex-PodViewer

NO_ARCH=	yes

USES=		desktop-file-utils gettext gmake gnome magick:6,build,run perl5 tar:xz
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
		 's|1p|1|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
