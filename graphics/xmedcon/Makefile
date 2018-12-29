# Created by: Paul Everlund
# $FreeBSD$

PORTNAME=	xmedcon
PORTVERSION=	0.16.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/XMedCon-Source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical image conversion utility and library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome libtool localbase pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/xmedcon \
		--enable-llcheck
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	X11 GLIB ACR_NEMA ANALYZE CONCORDE DICOM DICOM_LJPEG ECAT GIF \
		INTERFILE INW PNG
OPTIONS_DEFAULT=X11 GLIB ACR_NEMA ANALYZE CONCORDE DICOM DICOM_LJPEG ECAT GIF \
		INTERFILE INW PNG
OPTIONS_SUB=	yes

X11_CONFIGURE_ENABLE=	gui
X11_USE=		GNOME=gtk20
X11_DESKTOP_ENTRIES=	"XMedCon" \
			"" \
			"${PREFIX}/etc/xmedcon.png" \
			"${PORTNAME}" \
			"" \
			""

GLIB_DESC=		With Glib
GLIB_CONFIGURE_ENABLE=	glib
GLIB_USE=		GNOME=glib20

ACR_NEMA_DESC=		With Acr/Nema 2.0

ANALYZE_DESC=		With Analyze (SPM)
ANALYZE_CONFIGURE_ENABLE=	anlz

CONCORDE_DESC=		With Concorde __ET
CONCORDE_CONFIGURE_ENABLE=	conc

DICOM_DESC=		With DICOM 3.0

DICOM_LJPEG_DESC=	With DICOM 3.0 Lossless JPEG
DICOM_LJPEG_CONFIGURE_ENABLE=	ljpg

ECAT_DESC=		With CTI ECAT 6/7
ECAT_CONFIGURE_ENABLE=	ecat

INTERFILE_DESC=		With InterFile 3.3
INTERFILE_CONFIGURE_ENABLE=	intf

INW_DESC=		With INW (RUG)
INW_CONFIGURE_ENABLE=	inw

GIF_CONFIGURE_OFF=	--disable-gif

PNG_CONFIGURE_ENABLE=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MACR_NEMA) || empty(PORT_OPTIONS:MDICOM)
CONFIGURE_ARGS+=	--disable-acr
.endif

.if empty(PORT_OPTIONS:MDICOM) || empty(PORT_OPTIONS:MDICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-dicom
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|etc||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^configheadersdir/s|=.*$$|= $$(includedir)|g' \
		${WRKSRC}/source/Makefile.in
	@${REINPLACE_CMD} -e '/xmedcon.1/d' \
		${WRKSRC}/man/Makefile.in

post-install-X11-on:
.for file in xmedcon.png xmedconrc xmedconrc.linux
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${STAGEDIR}${PREFIX}/etc
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/xmedcon.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
