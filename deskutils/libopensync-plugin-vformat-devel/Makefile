# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-vformat
PORTVERSION=	0.39
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Vformat plugin for the OpenSync framework

LIB_DEPENDS=	opensync:${PORTSDIR}/devel/libopensync

USE_BZIP2=	yes
USES=		cmake iconv pkgconfig
CMAKE_ARGS+=	-Wno-dev
CFLAGS+=	"-I${LOCALBASE}/include"

pre-patch:
	@${REINPLACE_CMD} -e "/FIND_PACKAGE( Check )/d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s|MESSAGE|# MESSAGE|" \
		${WRKSRC}/cmake/modules/MacroEnsureOutOfSourceBuild.cmake

.include <bsd.port.mk>
