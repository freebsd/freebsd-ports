# Created by: Kirill Ponomarew <ponomarew@oberon.net>

PORTNAME=	kyra
PORTVERSION=	2.1.3
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTVERSION}
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Sprite engine written in C++

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

BROKEN_aarch64=		invalid output constraint =A in assembler
BROKEN_armv6=		invalid output constraint =A in assembler
BROKEN_armv7=		invalid output constraint =A in assembler

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		compiler gl gmake jpeg sdl zip
USE_GL=		gl
USE_SDL=	image sdl

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

MAKEFILE=	MakefileKyra
MAKE_ENV=	MAKE_KYRA=RELEASE KYRA_OPENGL=YES
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" LD="${CXX}" \
		RELEASE_CFLAGS="${CFLAGS}" RELEASE_CXXFLAGS="${CXXFLAGS}"

do-install:
.for i in encoder spriteed
	(cd ${WRKSRC}/${i} && ${INSTALL_PROGRAM} kr${i} ${STAGEDIR}${PREFIX}/bin)
.endfor
	(cd ${WRKSRC}/engine && ${INSTALL_DATA} libkyra.a ${STAGEDIR}${PREFIX}/lib)
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/Kyra
	(cd ${WRKSRC} && ${INSTALL_DATA} kyra.h ${STAGEDIR}${PREFIX}/include/Kyra)
.for i in engine gui guiExtended util
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/Kyra/${i}
	(cd ${WRKSRC}/${i} && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/Kyra/${i})
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/Kyra/tinyxml
	(cd ${WRKSRC}/../tinyxml && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/Kyra/tinyxml)

.include <bsd.port.mk>
