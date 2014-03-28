# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtimelapse
DISTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Relase	# yes, this is not a typo (here)

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application for capturing images to generate timelapse videos

LICENSE=	GPLv2

LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		pkgconfig
USE_WX=		3.0
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
LIBTOOLIZE_ARGS=--copy --force
AUTOMAKE_ARGS=	--add-missing --copy

PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES="gTimelapse" "" "" "${PORTNAME}" "Graphics;GTK;" ""

.include <bsd.port.mk>
