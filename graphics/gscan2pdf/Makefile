# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gscan2pdf
PORTVERSION=	1.3.5
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Config-General>=2.40:${PORTSDIR}/devel/p5-Config-General \
		p5-Glib2>=1.210:${PORTSDIR}/devel/p5-Glib2 \
		p5-Goo-Canvas>0:${PORTSDIR}/devel/p5-Goo-Canvas \
		p5-Locale-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly \
		ImageMagick>0:${PORTSDIR}/graphics/ImageMagick \
		p5-Sane>=0.05:${PORTSDIR}/graphics/p5-Sane \
		p5-Set-IntSpan>=1.10:${PORTSDIR}/math/p5-Set-IntSpan \
		p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
		bash:${PORTSDIR}/shells/bash \
		p5-PDF-API2>0.57:${PORTSDIR}/textproc/p5-PDF-API2 \
		p5-Gtk2>=1.090:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-Simple-List>0:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-Simple-List \
		p5-Gtk2-ImageView>0:${PORTSDIR}/x11-toolkits/p5-Gtk2-ImageView
RUN_DEPENDS:=	p5-Archive-Tar>0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Proc-ProcessTable>0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		cjb2:${PORTSDIR}/graphics/djvulibre \
		scanimage:${PORTSDIR}/graphics/sane-backends \
		scanadf:${PORTSDIR}/graphics/sane-frontends \
		unpaper:${PORTSDIR}/graphics/unpaper \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Gtk2-Ex-PodViewer>0.17:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-Filesys-Df>0.92:${PORTSDIR}/sysutils/p5-Filesys-Df \
		p5-Data-UUID>=1.220:${PORTSDIR}/devel/p5-Data-UUID \
		${BUILD_DEPENDS}

NO_ARCH=	yes

USES=		gettext gmake perl5 tar:xz
USE_GNOME=	gtk20 librsvg2
USE_PERL5=	configure

OPTIONS_MULTI=		OCR
OPTIONS_MULTI_OCR=	CUNEIFORM GOCR OCROPUS TESSERACT
OPTIONS_DEFAULT=	GOCR

CUNEIFORM_DESC=		Multi-language OCR system
CUNEIFORM_RUN_DEPENDS=	cuneiform:${PORTSDIR}/graphics/cuneiform
GOCR_DESC=		OCR program developed under GPL
GOCR_RUN_DEPENDS=	gocr:${PORTSDIR}/graphics/gocr
OCR_DESC=		Optical Character Recognition
OCROPUS_DESC=		Document analysis and OCR system
OCROPUS_RUN_DEPENDS=	ocropus:${PORTSDIR}/graphics/ocropus
TESSERACT_DESC=		OCR engine developed at Google
TESSERACT_RUN_DEPENDS=	tesseract:${PORTSDIR}/graphics/tesseract

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$sharedir/man|$$prefixdir/man| ; \
		 s|1p|1|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
