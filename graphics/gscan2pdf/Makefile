# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gscan2pdf
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Set-IntSpan>=0:${PORTSDIR}/math/p5-Set-IntSpan \
		p5-XML-LibXML-Simple>=0:${PORTSDIR}/textproc/p5-XML-LibXML-Simple \
		p5-Sys-SigAction>=0:${PORTSDIR}/devel/p5-Sys-SigAction \
		p5-forks>=0:${PORTSDIR}/devel/p5-forks \
		p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		convert:${PORTSDIR}/graphics/ImageMagick \
		p5-Goo-Canvas>=0:${PORTSDIR}/devel/p5-Goo-Canvas \
		p5-Pango>=0:${PORTSDIR}/x11-toolkits/p5-Pango \
		p5-Acme-Damn>=0:${PORTSDIR}/devel/p5-Acme-Damn \
		p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Locale-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		cjb2:${PORTSDIR}/graphics/djvulibre \
		gocr:${PORTSDIR}/graphics/gocr \
		p5-Sane>=0:${PORTSDIR}/graphics/p5-Sane \
		scanimage:${PORTSDIR}/graphics/sane-backends \
		scanadf:${PORTSDIR}/graphics/sane-frontends \
		tesseract:${PORTSDIR}/graphics/tesseract \
		unpaper:${PORTSDIR}/graphics/unpaper \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		ocropus:${PORTSDIR}/graphics/ocropus \
		p5-PDF-API2>=0.57:${PORTSDIR}/textproc/p5-PDF-API2 \
		p5-Gtk2>=1.112:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-PodViewer>=0.17:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-Gtk2-Ex-Simple-List>=0.50:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-Simple-List \
		p5-Gtk2-ImageView>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2-ImageView \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Locale-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		cjb2:${PORTSDIR}/graphics/djvulibre \
		gocr:${PORTSDIR}/graphics/gocr \
		p5-Sane>=0:${PORTSDIR}/graphics/p5-Sane \
		scanimage:${PORTSDIR}/graphics/sane-backends \
		scanadf:${PORTSDIR}/graphics/sane-frontends \
		tesseract:${PORTSDIR}/graphics/tesseract \
		unpaper:${PORTSDIR}/graphics/unpaper \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		ocropus:${PORTSDIR}/graphics/ocropus \
		p5-PDF-API2>=0.57:${PORTSDIR}/textproc/p5-PDF-API2 \
		p5-Gtk2>=1.112:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-PodViewer>=0.17:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-Gtk2-Ex-Simple-List>=0.50:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-Simple-List \
		p5-Gtk2-ImageView>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2-ImageView \
		bash:${PORTSDIR}/shells/bash

USES=		gmake perl5
USE_GNOME=	gtk20 librsvg2
USE_PERL5=	configure
MAN1=		${PORTNAME}.1 scanadf-perl.1 scanimage-perl.1
PORT_VERBS=	${PORTNAME} Gscan2pdf

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/--parents/-p/g;s|$$sharedir/man|${MANPREFIX}/man|g;s|1p|1|g'\
		-e '/SITEPREFIX/s|/usr|${PREFIX}|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
