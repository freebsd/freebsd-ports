# New ports collection makefile for:	xmedcon
# Date created:		26 September 2002
# Whom:			Paul Everlund
#
# $FreeBSD$
#

PORTNAME=	xmedcon
PORTVERSION=	0.8.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tdv94ped@cs.umu.se

USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.if defined(WITHOUT_X11)
CONFIGURE_ARGS=	--disable-gui
PKGNAMESUFFIX=	-nox11
PLIST_SUB=	X11="@comment "
.else
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 gdkpixbuf
PLIST_SUB=	X11=""
.endif

.if defined(NOACR) && defined(NODICOM)
CONFIGURE_ARGS+=	--disable-acr
.endif
.if defined(NOGIF)
CONFIGURE_ARGS+=	--disable-gif
.endif
.if defined(NOINW)
CONFIGURE_ARGS+=	--disable-inw
.endif
.if defined(NOANLZ)
CONFIGURE_ARGS+=	--disable-anlz
.endif
.if defined(NOCONC)
CONFIGURE_ARGS+=	--disable-conc
.endif
.if defined(NOECAT)
CONFIGURE_ARGS+=	--disable-ecat
.endif
.if defined(NOINTF)
CONFIGURE_ARGS+=	--disable-intf
.endif
.if defined(NODICOM)
CONFIGURE_ARGS+=	--disable-dicom
.endif
.if defined(NOLJPG)
CONFIGURE_ARGS+=	--disable-ljpg
PLIST_SUB+=		LJPG="@comment "
.else
PLIST_SUB+=		LJPG=""
.endif
.if defined(NOPNG)
CONFIGURE_ARGS+=	--disable-png
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/xmedcon

MAN1=	medcon.1 xmedcon-config.1
.if !defined(WITHOUT_X11)
MAN1+=	xmedcon.1
.endif
MAN3=	medcon.3
MAN4=	m-acr.4 m-anlz.4 m-ecat.4 m-gif.4 m-intf.4 m-inw.4

.include <bsd.port.mk>
