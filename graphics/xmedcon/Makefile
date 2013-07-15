# Created by: Paul Everlund
# $FreeBSD$

PORTNAME=	xmedcon
PORTVERSION=	0.13.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/XMedCon-Source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical image conversion utility and library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

OPTIONS_DEFINE=	X11 GLIB ACR_NEMA ANALYZE CONCORDE DICOM DICOM_LJPEG ECAT GIF INTERFILE INW PNG
OPTIONS_DEFAULT=X11 GLIB ACR_NEMA ANALYZE CONCORDE DICOM DICOM_LJPEG ECAT GIF INTERFILE INW PNG
GLIB_DESC=	With Glib
ACR_NEMA_DESC=	With Acr/Nema 2.0
ANALYZE_DESC=	With Analyze (SPM)
CONCORDE_DESC=	With Concorde __ET
DICOM_DESC=	With DICOM 3.0
DICOM_LJPEG_DESC=	With DICOM 3.0 Lossless JPEG
ECAT_DESC=	With CTI ECAT 6/7
INTERFILE_DESC=	With InterFile 3.3
INW_DESC=	With INW (RUG)

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/xmedcon \
		--enable-llcheck
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		medcon.1 xmedcon-config.1
MAN3=		medcon.3
MAN4=		m-acr.4 m-anlz.4 m-ecat.4 m-gif.4 m-intf.4 m-inw.4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_GNOME+=	gtk20
PLIST_SUB+=	X11=""
MAN1+=		xmedcon.1
DESKTOP_ENTRIES="XMedCon" "" "${PREFIX}/etc/xmedcon.png" "${PORTNAME}" "" ""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MGLIB}
USE_GNOME+=	glib20
.else
CONFIGURE_ARGS+=	--disable-glib
.endif

.if empty(PORT_OPTIONS:MACR_NEMA) || empty(PORT_OPTIONS:MDICOM)
CONFIGURE_ARGS+=	--disable-acr
.endif

.if empty(PORT_OPTIONS:MGIF)
CONFIGURE_ARGS+=	--disable-gif
.endif

.if empty(PORT_OPTIONS:MINW)
CONFIGURE_ARGS+=	--disable-inw
.endif

.if empty(PORT_OPTIONS:MANALYZE)
CONFIGURE_ARGS+=	--disable-anlz
.endif

.if empty(PORT_OPTIONS:MCONCORDE)
CONFIGURE_ARGS+=	--disable-conc
.endif

.if empty(PORT_OPTIONS:MECAT)
CONFIGURE_ARGS+=	--disable-ecat
.endif

.if empty(PORT_OPTIONS:MINTERFILE)
CONFIGURE_ARGS+=	--disable-intf
.endif

.if empty(PORT_OPTIONS:MDICOM) || empty(PORT_OPTIONS:MDICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-dicom
.endif

.if empty(PORT_OPTIONS:MDICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-ljpg
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=		png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--disable-png
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|etc||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^configheadersdir/s|=.*$$|= $$(includedir)|g' \
		${WRKSRC}/source/Makefile.in
	@${REINPLACE_CMD} -e '/xmedcon.1/d' \
		${WRKSRC}/man/Makefile.in

post-install:
.if ${PORT_OPTIONS:MX11}
.for file in xmedcon.png xmedconrc xmedconrc.linux
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${PREFIX}/etc
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/xmedcon.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
