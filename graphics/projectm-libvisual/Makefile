# $FreeBSD$

PORTNAME=	projectM-libvisual
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	graphics audio
MASTER_SITES=	SF/${PORTNAME:tl:S/-libvisual//}/${PORTVERSION}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}-Source

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Allows projectM to be used with libvisual

LICENSE=	GPLv2

LIB_DEPENDS=	libprojectM.so:graphics/libprojectm \
		libvisual-${LIBVISUAL_VER}.so:graphics/libvisual${LIBVISUAL_VER:S/.//} \
		libSDL.so:devel/sdl12

USES=		cmake pkgconfig
CMAKE_ARGS+=	-DLIBVISUAL_LIBRARIES=visual-${LIBVISUAL_VER}
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIBVISUAL_VER=	0.4

PLIST_FILES=	lib/libvisual-${LIBVISUAL_VER}/actor/libprojectM_libvisual.so

post-patch:
	@${FIND} ${WRKSRC} -name "*.[hc]*" | ${XARGS} ${REINPLACE_CMD} \
		-e 's#<libvisual#<libvisual-${LIBVISUAL_VER}/libvisual#g'
	@${REINPLACE_CMD} -e 's#/usr/local#${PREFIX}#' \
		${WRKSRC}/CPackConfig.cmake \
		${WRKSRC}/cmake_install.cmake \
		${WRKSRC}/CPackSourceConfig.cmake

.include <bsd.port.mk>
