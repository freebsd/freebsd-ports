# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-vformat
PORTVERSION=	0.39
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/ \
		LOCAL/danilo
PKGNAMESUFFIX=	-devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Vformat plugin for the OpenSync framework

LIB_DEPENDS=	libopensync.so:devel/libopensync

USES=		cmake iconv pkgconfig tar:bzip2
CMAKE_ARGS+=	-Wno-dev
CFLAGS+=	"-I${LOCALBASE}/include"

pre-patch:
	@${REINPLACE_CMD} -e "/FIND_PACKAGE( Check )/d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s|MESSAGE|# MESSAGE|" \
		${WRKSRC}/cmake/modules/MacroEnsureOutOfSourceBuild.cmake

.include <bsd.port.mk>
