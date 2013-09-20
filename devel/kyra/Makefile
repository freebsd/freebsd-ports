# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	kyra
PORTVERSION=	2.1.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTVERSION}
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Sprite engine written in C++

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_GL=		gl
USE_SDL=	image sdl
USE_GMAKE=	yes
MAKEFILE=	MakefileKyra
MAKE_ENV=	MAKE_KYRA=RELEASE KYRA_OPENGL=YES
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" LD="${CXX}" \
		RELEASE_CFLAGS="${CFLAGS}" RELEASE_CXXFLAGS="${CXXFLAGS}"

NO_STAGE=	yes
do-install:
.for i in encoder spriteed
	(cd ${WRKSRC}/${i} && ${INSTALL_PROGRAM} kr${i} ${PREFIX}/bin)
.endfor
	(cd ${WRKSRC}/engine && ${INSTALL_DATA} libkyra.a ${PREFIX}/lib)
	@${MKDIR} ${PREFIX}/include/Kyra
	(cd ${WRKSRC} && ${INSTALL_DATA} kyra.h ${PREFIX}/include/Kyra)
.for i in engine gui guiExtended util
	@${MKDIR} ${PREFIX}/include/Kyra/${i}
	(cd ${WRKSRC}/${i} && ${INSTALL_DATA} *.h ${PREFIX}/include/Kyra/${i})
.endfor
	@${MKDIR} ${PREFIX}/include/Kyra/tinyxml
	(cd ${WRKSRC}/../tinyxml && ${INSTALL_DATA} *.h \
		${PREFIX}/include/Kyra/tinyxml)

.include <bsd.port.mk>
