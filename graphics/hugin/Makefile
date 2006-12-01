# New ports collection makefile for:   hugin
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	hugin
PORTVERSION=	0.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	cartola@openit.com.br
COMMENT=	A GUI for Panorama Tools, to stitch panoramic images

BUILD_DEPENDS=	PTOptimizer:${PORTSDIR}/graphics/libpano12 \
		vigra-config:${PORTSDIR}/graphics/vigra
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		fftw:${PORTSDIR}/math/fftw \
		boost_date_time:${PORTSDIR}/devel/boost
RUN_DEPENDS=	PTOptimizer:${PORTSDIR}/graphics/libpano12 \
		PTStitcher:${PORTSDIR}/graphics/linux-panorama-tools

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -ftemplate-depth-64" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_ICONV=	yes
USE_WX=		2.6
WX_CONF_ARGS=	absolute

DOCSDIR=	${PREFIX}/share/hugin/xrc/data

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-wxrc|-${WX_CONFIG:S/wx/wxrc/}|' \
		${WRKSRC}/src/hugin/xrc/Makefile.in

.include <bsd.port.mk>
