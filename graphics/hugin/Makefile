# New ports collection makefile for:   hugin
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	hugin
PORTVERSION=	0.6.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	A GUI for Panorama Tools, to stitch panoramic images

BUILD_DEPENDS=	libpano12>=2.8.4:${PORTSDIR}/graphics/libpano12 \
		vigra-config:${PORTSDIR}/graphics/vigra \
		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		fftw:${PORTSDIR}/math/fftw \
		boost_date_time:${PORTSDIR}/devel/boost
RUN_DEPENDS=	PTOptimizer:${PORTSDIR}/graphics/libpano12 \
		PTStitcher:${PORTSDIR}/graphics/linux-panorama-tools

USE_BZIP2=	yes

USE_AUTOTOOLS=	autoconf:259:env autoheader:259:env aclocal:19:env \
		automake:19:env libtool:15:env

IS_INTERACTIVE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} WXRC=${WXRC_CMD}
CONFIGURE_ARGS+=	--with-boost=${LOCALBASE} \
			--disable-desktop
USE_GMAKE=	yes
USE_ICONV=	yes
USE_WX=		2.6
WX_CONF_ARGS=	absolute

MAN1=		fulla.1

DOCSDIR=	${PREFIX}/share/hugin/xrc/data

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

pre-configure:
	cd ${WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} \
	ACLOCAL="${ACLOCAL} -I ${LOCALBASE}/share/aclocal" \
	./bootstrap

.include <bsd.port.mk>
