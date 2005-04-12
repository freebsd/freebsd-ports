# New ports collection makefile for:	xmedcon
# Date created:		26 September 2002
# Whom:			Paul Everlund
#
# $FreeBSD$
#

PORTNAME=		xmedcon
PORTVERSION=		0.9.8.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tdv94ped@cs.umu.se
COMMENT=	A medical image conversion utility and library

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_SUBMAKE=	yes

OPTIONS=	X11 "With X11" on \
		GLIB "With Glib" on \
		ACR_NEMA "With Acr/Nema 2.0" on \
		ANALYZE "With Analyze (SPM)" on \
		CONCORDE "With Concorde µPET" on \
		DICOM "With DICOM 3.0" on \
		DICOM_LJPEG "With DICOM 3.0 Lossless JPEG" on \
		ECAT "With CTI ECAT 6/7" on \
		GIF "With GIF87a/89a" on \
		INTERFILE "With InterFile 3.3" on \
		INW "With INW (RUG)" on \
		PNG "With PNG" on

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--enable-llcheck

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	X11="@comment "
.else
USE_GNOME+=	gtk12 gdkpixbuf
PLIST_SUB+=	X11=""
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITHOUT_GLIB)
CONFIGURE_ARGS+=	--disable-glib
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

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/xmedcon

MAN1=	medcon.1 xmedcon-config.1
.if !defined(WITHOUT_X11)
MAN1+=	xmedcon.1
.endif

MAN3=	medcon.3

MAN4=	m-acr.4 m-anlz.4 m-ecat.4 m-gif.4 m-intf.4 m-inw.4

.include <bsd.port.post.mk>
