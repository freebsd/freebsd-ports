# $FreeBSD$

PORTNAME=	amide
PORTVERSION=	1.0.5
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Medical Imaging Data Examiner

LICENSE=	GPLv2

BUILD_DEPENDS=	gm4:devel/m4

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
MAKE_JOBS_UNSAFE=	yes
USES=		gettext gmake pkgconfig tar:tgz
USE_GNOME=	gtk20 intltool libgnomecanvas libgnomeui libxml2 gnomedocutils
INSTALLS_OMF=	yes

OPTIONS_DEFINE=	CODEC DCMTK GSL NLS VOLPACK XMEDCON
OPTIONS_SINGLE=	CODEC
OPTIONS_SINGLE_CODEC=	FFMPEG FAME
OPTIONS_DEFAULT=	CODEC DCMTK FFMPEG GSL VOLPACK XMEDCON

CODEC_DESC=	Enable codec support. Choose one of FAME or FFMPEG
DCMTK_DESC=	Use dcmtk
FAME_DESC=	Use libfame
FFMPEG_DESC=	Use ffmpeg
GSL_DESC=	Use gsl
VOLPACK_DESC=	Use volpack
XMEDCON_DESC=	Use xmedcon

OPTIONS_SUB=			yes
DCMTK_CONFIGURE_ENABLE=		libdcmdata
DCMTK_LIB_DEPENDS=		libdcmdata.so:devel/dcmtk
FAME_CONFIGURE_ENABLE=		libfame
FAME_LIB_DEPENDS=		libfame.so:multimedia/libfame
FFMPEG_CONFIGURE_ENABLE=	ffmpeg
FFMPEG_LIB_DEPENDS=		libavcodec0.so:multimedia/ffmpeg0
GSL_CONFIGURE_ENABLE=		libgsl
GSL_LIB_DEPENDS=		libgsl.so:math/gsl
VOLPACK_CONFIGURE_ENABLE=	libvolpack
VOLPACK_BUILD_DEPENDS=		${LOCALBASE}/lib/libvolpack.a:graphics/volpack
XMEDCON_CONFIGURE_ENABLE=	libmdc
XMEDCON_LIB_DEPENDS=		libmdc.so:graphics/xmedcon
NLS_CONFIGURE_ENABLE=		nls

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/amide_config.h.in
	@${REINPLACE_CMD} \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|libavcodec|libavcodec0|g' \
		-e 's|libavutil|libavutil0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
