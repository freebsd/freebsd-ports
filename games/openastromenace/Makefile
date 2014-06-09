# Created by: Oleg Alexeenkov
# $FreeBSD$

PORTNAME=	openastromenace
PORTVERSION=	1.2.0
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/openastromenace/openastromenace/1.2.0/:source \
		SF/openastromenace/openastromenace%20vfs/1.2.0/:data
DISTFILES=	openamenace-src-${PORTVERSION}${EXTRACT_SUFX}:source \
		oamenace-data-1.2.0.tar.bz2:data \
		oamenace-lang-${LANGPACK}-${PORTVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities

LIB_DEPENDS+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USES=		tar:bzip2 cmake dos2unix openal:al,alut
USE_GL=		gl glu
USE_SDL=	sdl
WRKSRC=		${WRKDIR}/OpenAstroMenaceSVN

PLIST_FILES=	bin/AstroMenace
PORTDATA=	*

OPTIONS_SINGLE=	LANG
OPTIONS_SINGLE_LANG=	EN DE RU
OPTIONS_DEFAULT=EN

EN_DESC=	"English language pack"
DE_DESC=	"German language pack"
RU_DESC=	"Russian language pack"

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
	${INSTALL_PROGRAM} ${WRKSRC}/AstroMenace ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/gamedata.vfs ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DATADIR}/DATA/SCRIPT
	${INSTALL_DATA} ${WRKDIR}/DATA/SCRIPT/* ${STAGEDIR}${DATADIR}/DATA/SCRIPT
	${INSTALL_DATA} ${WRKDIR}/gamelang_${LANGPACK}.vfs \
		${STAGEDIR}${DATADIR}/gamelang.vfs

.include <bsd.port.post.mk>
