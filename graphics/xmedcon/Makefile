# New ports collection makefile for:	xmedcon
# Date created:		26 September 2002
# Whom:			Paul Everlund
#
# $FreeBSD$
#

PORTNAME=	xmedcon
PORTVERSION=	0.8.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tdv94ped@cs.umu.se

USE_SUBMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		MKDIR="${MKDIR}" \
		REALCURDIR=${.CURDIR}

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if defined(WITH_X11)
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 gdkpixbuf
PLIST_SUB=	X11=""
.else
CONFIGURE_ARGS=	--disable-gui
PKGNAMESUFFIX=	-nox11
PLIST_SUB=	X11="@comment "
.endif

.if !defined(WITH_ACRNEMA) && !defined(WITH_DICOM)
CONFIGURE_ARGS+=	--disable-acr
.endif

.if !defined(WITH_GIF)
CONFIGURE_ARGS+=	--disable-gif
.endif

.if !defined(WITH_INW)
CONFIGURE_ARGS+=	--disable-inw
.endif

.if !defined(WITH_ANALYZE)
CONFIGURE_ARGS+=	--disable-anlz
.endif

.if !defined(WITH_CONCORDE)
CONFIGURE_ARGS+=	--disable-conc
.endif

.if !defined(WITH_ECAT)
CONFIGURE_ARGS+=	--disable-ecat
.endif

.if !defined(WITH_INTERFILE)
CONFIGURE_ARGS+=	--disable-intf
.endif

.if !defined(WITH_DICOM) && !defined(WITH_DICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-dicom
.endif

.if !defined(WITH_DICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-ljpg
.endif

.if !defined(WITH_PNG)
CONFIGURE_ARGS+=	--disable-png
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/xmedcon

MAN1=	medcon.1 xmedcon-config.1
.if defined(WITH_X11)
MAN1+=	xmedcon.1
.endif

MAN3=	medcon.3

MAN4=	m-acr.4 m-anlz.4 m-ecat.4 m-gif.4 m-intf.4 m-inw.4

.include <bsd.port.mk>
