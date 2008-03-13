# New ports collection makefile for: openastromenace
# Date created:		23 Sep 2007
# Whom:			Oleg Alexeenkov
#
# $FreeBSD$
#

PORTNAME=	openastromenace
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	proler@gmail.com
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities

USE_BZIP2=	yes
USE_GL=		yes
WANT_SDL=	yes
USE_SDL=	sdl

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

SUB_FILES=	pkg-message

BUILD_DEPENDS+=	${LOCALBASE}/bin/cmake:${PORTSDIR}/devel/cmake	\

LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis	\
		jpeg:${PORTSDIR}/graphics/jpeg	\
		openal:${PORTSDIR}/audio/openal	\
		alut:${PORTSDIR}/audio/freealut	\

OPTIONS=	SRC        	"build src"	on	\
		DATA        	"install data file"	on	\
		EN        	" en lang"	on	\
		DE        	" de lang "	on	\
		RU        	" ru lang "	on	\

.include <bsd.port.pre.mk>

.undef DISTFILES
.if defined(WITH_SRC)
DISTFILES+=oamenace-src-${PORTVERSION}.tar.bz2
.else
NO_BUILD=	yes
.endif
.if defined(WITH_DATA)
DISTFILES+=oamenace-data-${PORTVERSION}.tar.bz2
.endif
.if defined(WITH_EN)
DISTFILES+=oamenace-lang-en-${PORTVERSION}.tar.bz2
.endif
.if defined(WITH_DE)
DISTFILES+=oamenace-lang-de-${PORTVERSION}.tar.bz2
.endif
.if defined(WITH_RU)
DISTFILES+=oamenace-lang-ru-${PORTVERSION}.tar.bz2
.endif

do-configure:
.if defined(WITH_SRC)
	@(cd ${WRKSRC}; \
	${LOCALBASE}/bin/cmake ${CMAKE_ARGS} ${PATCH_WRKSRC})
.endif

do-install:
.if defined(WITH_SRC)
	${INSTALL_PROGRAM} ${WRKSRC}/AstroMenace ${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}
.if defined(WITH_DATA)
	${INSTALL_DATA} ${WRKDIR}/gamedata.vfs ${DATADIR}/
	${MKDIR} ${DATADIR}/DATA/SCRIPT
	${INSTALL_DATA} ${WRKDIR}/DATA/SCRIPT/* ${DATADIR}/DATA/SCRIPT
.endif
.if defined(WITH_EN)
	${INSTALL_DATA} ${WRKDIR}/gamelang_en.vfs ${DATADIR}/
	${LN} -sf ${DATADIR}/gamelang_en.vfs ${DATADIR}/gamelang.vfs
.endif
.if defined(WITH_DE)
	${INSTALL_DATA} ${WRKDIR}/gamelang_de.vfs ${DATADIR}/
	${LN} -sf ${DATADIR}/gamelang_de.vfs ${DATADIR}/gamelang.vfs
.endif
.if defined(WITH_RU)
	${INSTALL_DATA} ${WRKDIR}/gamelang_ru.vfs ${DATADIR}/
	${LN} -sf ${DATADIR}/gamelang_ru.vfs ${DATADIR}/gamelang.vfs
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
