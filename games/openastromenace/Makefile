# Created by: Oleg Alexeenkov
# $FreeBSD$

PORTNAME=	openastromenace
PORTVERSION=	1.2.0
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:source,data/}
DISTFILES=	openamenace-src-${PORTVERSION}${EXTRACT_SUFX}:source \
		oamenace-data-1.2.0.tar.bz2:data \
		oamenace-lang-${LANGPACK}-${PORTVERSION}${EXTRACT_SUFX}:data
MASTER_SITE_SUBDIR=     openastromenace/openastromenace/1.2.0/:source \
                        openastromenace/openastromenace%20vfs/1.2.0/:data

MAINTAINER=	proler@gmail.com
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities

LIB_DEPENDS+=	vorbisfile:${PORTSDIR}/audio/libvorbis \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_GL=		gl glu
WANT_SDL=	yes
USE_SDL=	sdl
USES=		cmake dos2unix openal:al,alut
WRKSRC=		${WRKDIR}/OpenAstroMenaceSVN

OPTIONS_SINGLE=	LANG
OPTIONS_SINGLE_LANG=	EN DE RU
OPTIONS_DEFAULT=EN

EN_DESC=	"English language pack"
DE_DESC=	"German language pack"
RU_DESC=	"Russian language pack"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEN}
LANGPACK=	en
.elif ${PORT_OPTIONS:MDE}
LANGPACK=	de
.elif ${PORT_OPTIONS:MRU}
LANGPACK=	ru
.endif

.if !defined(WITHOUT_NOUVEAU)
CFLAGS+=	-DOLD_MESA
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
