# New ports collection makefile for:	xmedcon
# Date created:		26 September 2002
# Whom:			Paul Everlund
#
# $FreeBSD$
#

PORTNAME=	xmedcon
PORTVERSION=	0.10.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A medical image conversion utility and library

OPTIONS=	X11 "With X11" on \
		GLIB "With Glib" on \
		ACR_NEMA "With Acr/Nema 2.0" on \
		ANALYZE "With Analyze (SPM)" on \
		CONCORDE "With Concorde __ET" on \
		DICOM "With DICOM 3.0" on \
		DICOM_LJPEG "With DICOM 3.0 Lossless JPEG" on \
		ECAT "With CTI ECAT 6/7" on \
		GIF "With GIF87a/89a" on \
		INTERFILE "With InterFile 3.3" on \
		INW "With INW (RUG)" on \
		PNG "With PNG" on

WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_SUBMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/xmedcon \
		--enable-llcheck
USE_LDCONFIG=	yes

MAN1=	medcon.1 xmedcon-config.1
MAN3=	medcon.3
MAN4=	m-acr.4 m-anlz.4 m-ecat.4 m-gif.4 m-intf.4 m-inw.4

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	X11="@comment "
.else
USE_GNOME+=	gtk20
PLIST_SUB+=	X11=""
MAN1+=		xmedcon.1
.endif

.if defined(WITHOUT_GLIB)
CONFIGURE_ARGS+=	--disable-glib
.else
USE_GNOME+=	glib20
.endif

.if defined(WITHOUT_ACR_NEMA) || defined(WITHOUT_DICOM)
CONFIGURE_ARGS+=	--disable-acr
.endif

.if defined(WITHOUT_GIF)
CONFIGURE_ARGS+=	--disable-gif
.endif

.if defined(WITHOUT_INW)
CONFIGURE_ARGS+=	--disable-inw
.endif

.if defined(WITHOUT_ANALYZE)
CONFIGURE_ARGS+=	--disable-anlz
.endif

.if defined(WITHOUT_CONCORDE)
CONFIGURE_ARGS+=	--disable-conc
.endif

.if defined(WITHOUT_ECAT)
CONFIGURE_ARGS+=	--disable-ecat
.endif

.if defined(WITHOUT_INTERFILE)
CONFIGURE_ARGS+=	--disable-intf
.endif

.if defined(WITHOUT_DICOM) || defined(WITHOUT_DICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-dicom
.endif

.if defined(WITHOUT_DICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-ljpg
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--disable-png
.else
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|etc||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^configheadersdir/s|=.*$$|= $$(includedir)|g' \
		${WRKSRC}/source/Makefile.in
	@${REINPLACE_CMD} -e '/xmedcon.1/d' \
		${WRKSRC}/man/Makefile.in

post-install:
.if !defined(WITHOUT_X11)
.for file in xmedcon.png xmedconrc xmedconrc.linux
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${PREFIX}/etc
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/xmedcon.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
