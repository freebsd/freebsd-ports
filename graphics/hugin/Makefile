# New ports collection makefile for:   hugin
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	hugin
DISTVERSION=	0.7_beta4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	A GUI for Panorama Tools, to stitch panoramic images

# zip is needed for building the help file
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	pano13:${PORTSDIR}/graphics/libpano13 \
		tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		boost_date_time:${PORTSDIR}/devel/boost

OPTIONS=	ENBLEND "enblend for high quality blending" on \
		AUTOPANOSIFT "autopano-sift for automatic control points" on \
		PTSTITCHER "PTStitcher for stitching images" on

USE_BZIP2=	yes

USE_AUTOTOOLS=	autoconf:261:env autoheader:261:env aclocal:110:env \
		automake:110:env libtool:15:env

IS_INTERACTIVE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} WXRC=${WXRC_CMD}
CONFIGURE_ARGS+=--with-boost=${LOCALBASE}
#		--disable-desktop
USE_GMAKE=	yes
USE_ICONV=	yes
USE_WX=		2.6
WX_CONF_ARGS=	absolute

.if defined(WX_UNICODE)
CONFIGURE_ARGS+=--with-unicode=yes
.else
CONFIGURE_ARGS+=--with-unicode=no
.endif

MAN1=		fulla.1

DOCSDIR=	${PREFIX}/share/hugin/xrc/data

.include <bsd.port.pre.mk>

.if defined(WITH_ENBLEND)
RUN_DEPENDS+=	enblend:${PORTSDIR}/graphics/enblend
.endif

.if defined(WITH_AUTOPANOSIFT)
RUN_DEPENDS+=	autopanog:${PORTSDIR}/graphics/autopano-sift
.endif

.if defined(WITH_PTSTITCHER)
RUN_DEPENDS+=	PTStitcher:${PORTSDIR}/graphics/linux-panorama-tools
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./bootstrap

.include <bsd.port.post.mk>
