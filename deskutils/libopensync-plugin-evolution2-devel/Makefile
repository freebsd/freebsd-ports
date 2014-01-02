# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-evolution2
PORTVERSION=	0.39
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Evolution 2 plugin for the OpenSync framework

LICENSE=	LGPL21

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync
RUN_DEPENDS=	vconvert:${PORTSDIR}/deskutils/libopensync-plugin-vformat-devel

CONFLICTS=	libopensync-plugin-evolution2-0.2*

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_GNOME=	evolutiondataserver gconf2

CMAKE_ARGS+=	-Wno-dev

pre-patch:
	    @${REINPLACE_CMD} -e "/FIND_PACKAGE( Check )/d" ${WRKSRC}/CMakeLists.txt
	    @${REINPLACE_CMD} -e "s|MESSAGE|# MESSAGE|" \
	    ${WRKSRC}/cmake/modules/MacroEnsureOutOfSourceBuild.cmake

.include <bsd.port.mk>
