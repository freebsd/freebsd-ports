# $FreeBSD$

PORTNAME=	iccexamin
PORTVERSION=	0.54
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/oyranos/ICC%20Examin/ICC%20Examin%20${PORTVERSION}
DISTNAME=	icc_examin-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	ICC profile viewer and colour visualisation

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/xdg-desktop-menu:${PORTSDIR}/devel/xdg-utils
LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk \
		ftgl:${PORTSDIR}/graphics/ftgl \
		lcms:${PORTSDIR}/graphics/lcms \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		oyranos:${PORTSDIR}/graphics/oyranos

MAKE_JOBS_UNSAFE=	yes
USES=		gettext iconv pkgconfig
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_XORG=	#
CONFIGURE_ARGS+=--mandir=${PREFIX}/man --prefix=${PREFIX}

MAN1=		iccexamin.1

NO_STAGE=	yes
.include <bsd.port.mk>
