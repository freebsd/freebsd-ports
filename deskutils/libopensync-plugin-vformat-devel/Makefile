# New ports collection makefile for:	libopensync-plugin-vformat-devel
# Date created:				16 June 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-vformat
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Vformat plugin for the OpenSync framework

LIB_DEPENDS=	opensync.1:${PORTSDIR}/devel/libopensync

USE_BZIP2=	yes
USE_ICONV=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_ARGS+=	-Wno-dev
CFLAGS+=	"-I${LOCALBASE}/include"

pre-patch:
	@${REINPLACE_CMD} -e "/FIND_PACKAGE( Check )/d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s|MESSAGE|# MESSAGE|" \
		${WRKSRC}/cmake/modules/MacroEnsureOutOfSourceBuild.cmake

.include <bsd.port.mk>
