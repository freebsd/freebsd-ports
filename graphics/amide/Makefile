# New ports collection makefile for:   amide
# Date created:        8 Feb 2011
# Whom:                Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	amide
PORTVERSION=	1.0.2
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Medical Imaging Data Examiner

LICENSE=	GPLv2

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 libgnomecanvas libgnomeui libxml2
INSTALLS_OMF=	yes

MAN1=		amide.1

OPTIONS_DEFINE=	DCMTK FAME FFMPEG GSL VOLPACK XMEDCON
OPTIONS_DEFAULT= DCMTK FFMPEG GSL VOLPACK XMEDCON

DCMTK_DESC=	"Use dcmtk"
FAME_DESC=	"Use libfame (mutually exclusive with ffmpeg)"
FFMPEG_DESC=	"Use ffmpeg (mutually exclusive with libfame)"
GSL_DESC=	"Use gsl"
VOLPACK_DESC=	"Use volpack"
XMEDCON_DESC=	"Use xmedcon"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDCMTK}
LIB_DEPENDS+=	dcmdata:${PORTSDIR}/devel/dcmtk
CONFIGURE_ARGS+=	--enable-libdcmdata
.else
CONFIGURE_ARGS+=	--disable-libdcmdata
.endif

.if ${PORT_OPTIONS:MFAME}
.  if${PORT_OPTIONS:MFFMPEG}
IGNORE=		libfame and ffmpeg support are mutually exclusive, please check options.
.  endif
LIB_DEPENDS+=	fame:${PORTSDIR}/multimedia/libfame
CONFIGURE_ARGS+=	--enable-libfame
.else
CONFIGURE_ARGS+=	--disable-libfame
.endif

.if ${PORT_OPTIONS:MFFMPEG}
.  if${PORT_OPTIONS:MFAME}
IGNORE=		libfame and ffmpeg support are mutually exclusive, please check options.
.  endif
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-ffmpeg
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl
CONFIGURE_ARGS+=	--enable-libgsl
.else
CONFIGURE_ARGS+=	--disable-libgsl
.endif

.if ${PORT_OPTIONS:MVOLPACK}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libvolpack.a:${PORTSDIR}/graphics/volpack
CONFIGURE_ARGS+=	--enable-libvolpack
.else
CONFIGURE_ARGS+=	--disable-libvolpack
.endif

.if ${PORT_OPTIONS:MXMEDCON}
LIB_DEPENDS+=	mdc:${PORTSDIR}/graphics/xmedcon
CONFIGURE_ARGS+=	--enable-libmdc
.else
CONFIGURE_ARGS+=	--disable-libmdc
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=''
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS='@comment '
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/amide_config.h.in
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
