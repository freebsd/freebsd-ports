# New ports collection makefile for: openastromenace
# Date created:		23 Sep 2007
# Whom:			Oleg Alexeenkov
#
# $FreeBSD$
#

PORTNAME=	openastromenace
PORTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	openamenace-src-${PORTVERSION}${EXTRACT_SUFX} \
		oamenace-data-${PORTVERSION}${EXTRACT_SUFX} \
		oamenace-lang-${LANGPACK}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	proler@gmail.com
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities

LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis \
		jpeg:${PORTSDIR}/graphics/jpeg	\
		openal:${PORTSDIR}/audio/openal	\
		alut:${PORTSDIR}/audio/freealut

USE_BZIP2=	yes
USE_GL=		gl glu
WANT_SDL=	yes
USE_SDL=	sdl
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/OpenAstroMenaceSVN

OPTIONS=	EN	"English language pack"	on \
		DE	"German language pack"	off \
		RU	"Russian language pack"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EN)
LANGPACK=	en
.elif defined(WITH_DE)
LANGPACK=	de
.elif defined(WITH_RU)
LANGPACK=	ru
.else
IGNORE=		cannot be build without/with multiple language packs. Please rerun 'make config' and select single language pack
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/share/openastromenace|${DATADIR}|' \
		${WRKSRC}/AstroMenaceSource/Main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AstroMenace ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/gamedata.vfs ${DATADIR}/
	${MKDIR} ${DATADIR}/DATA/SCRIPT
	${INSTALL_DATA} ${WRKDIR}/DATA/SCRIPT/* ${DATADIR}/DATA/SCRIPT
	${INSTALL_DATA} ${WRKDIR}/gamelang_${LANGPACK}.vfs \
		${DATADIR}/gamelang.vfs

.include <bsd.port.post.mk>
