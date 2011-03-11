# New ports collection makefile for:   amide
# Date created:        8 Feb 2011
# Whom:                Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	amide
PORTVERSION=	0.9.2
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	mad@madpilot.net
COMMENT=	Medical Imaging Data Examiner

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 libgnomecanvas libgnomeui libxml2
INSTALLS_OMF=	yes

MAN1=		amide.1

OPTIONS=	XMEDCON	"Use xmedcon"	on \
		DCMTK	"Use dcmtk"	on \
		FFMPEG	"Use ffmpeg"	on \
		GSL	"Use gsl"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XMEDCON)
LIB_DEPENDS+=	mdc.2:${PORTSDIR}/graphics/xmedcon
CONFIGUE_ARGS+=	--enable-libmdc
.else
CONFIGUE_ARGS+=	--disable-libmdc
.endif

.if !defined(WITHOUT_DCMTK)
LIB_DEPENDS+=	dcmdata.3:${PORTSDIR}/devel/dcmtk
CONFIGUE_ARGS+=	--enable-libdcmdata
.else
CONFIGUE_ARGS+=	--disable-libdcmdata
.endif

.if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGUE_ARGS+=	--enable-ffmpeg
.else
CONFIGUE_ARGS+=	--disable-ffmpeg
.endif

.if !defined(WITHOUT_GSL)
LIB_DEPENDS+=	gsl.15:${PORTSDIR}/math/gsl
CONFIGUE_ARGS+=	--enable-libgsl
.else
CONFIGUE_ARGS+=	--disable-libgsl
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS='@comment '
.else
PLIST_SUB+=	NLS=''
.endif

.include <bsd.port.post.mk>
