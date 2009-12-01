# New ports collection makefile for:	gscan2pdf
# Date created:		4 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gscan2pdf
PORTVERSION=	0.9.29
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Produce PDF from scanned documents

RUN_DEPENDS=	p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		ImageMagick>=6.3.3.5:${PORTSDIR}/graphics/ImageMagick \
		cjb2:${PORTSDIR}/graphics/djvulibre-nox11 \
		gocr:${PORTSDIR}/graphics/gocr \
		p5-Sane>=0:${PORTSDIR}/graphics/p5-Sane \
		scanimage:${PORTSDIR}/graphics/sane-backends \
		scanadf:${PORTSDIR}/graphics/sane-frontends \
		tesseract:${PORTSDIR}/graphics/tesseract \
		unpaper:${PORTSDIR}/graphics/unpaper \
		p5-PDF-API2>=0.57:${PORTSDIR}/textproc/p5-PDF-API2 \
		p5-Gtk2>=1.112:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Ex-PodViewer>=0.17:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-PodViewer \
		p5-Gtk2-Ex-Simple-List>=0.50:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-Simple-List \
		p5-Gtk2-ImageView>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2-ImageView

USE_GMAKE=	yes
USE_GNOME=	librsvg2
PERL_CONFIGURE=	yes
MAN1=		${PORTNAME}.1 scanadf-perl.1 scanimage-perl.1
PORT_VERBS=	${PORTNAME} Gscan2pdf

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/--parents/-p/g;s|$$sharedir/man|${MANPREFIX}/man|g;s|1p|1|g'\
		-e '/SITEPREFIX/s|/usr|${PREFIX}|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
