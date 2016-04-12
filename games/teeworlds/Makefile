# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	teeworlds
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://www.teeworlds.com/files/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} bam-${BAM_VERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Platform game featuring buggers equipped with weapons

LICENSE=	ZLIB

LIB_DEPENDS=	libfreetype.so:print/freetype2

CPE_VERSION=	${PORTVERSION:C/^0\.//}

USES=		cpe python:2,build
BAM_VERSION=	0.4.0
BAM_WRKSRC=	${WRKDIR}/bam-${BAM_VERSION}
BAM_TARGET=	release
USE_GCC=	any

PLIST_FILES+=	bin/${PORTNAME}_srv
PORTDATA=	*

OPTIONS_DEFINE=	SERVER_ONLY
SERVER_ONLY_DESC=Build dedicated server only

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not install on ia64: gets bus error
.endif

.if ${PORT_OPTIONS:MSERVER_ONLY}
BAM_TARGET=	server_release
PKGNAMESUFFX=	-server
.else
USE_XORG=	x11
USE_GL=		gl glu
USE_SDL=	sdl
PLIST_FILES+=	bin/${PORTNAME}
DESKTOP_ENTRIES="Teeworlds" \
		"Platform game featuring buggers equipped with weapons" \
		"${DATADIR}/Teeworlds.ico" \
		"${PORTNAME}" \
		"Game;ActionGame;" \
		""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"python "|"${PYTHON_CMD} "|' \
		${WRKSRC}/bam.lua
	@${REINPLACE_CMD} -e 's|-O.||; s|^gcc|${CC} ${CFLAGS}|; s|-ldl||g' \
		${BAM_WRKSRC}/make_unix.sh
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/other/sdl/sdl.lua
	@${REINPLACE_CMD} -e '/aDirs\[\]/,/}/ s|"/.*"|"${DATADIR}"|' \
		${WRKSRC}/src/engine/shared/storage.cpp
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|g++|${CXX}|' \
		${BAM_WRKSRC}/src/driver_gcc.lua ${WRKSRC}/configure.lua

# build bam executable - teeworlds own build system
pre-build:
	cd ${BAM_WRKSRC} && ${SH} -v make_unix.sh

# build teeworlds
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${BAM_WRKSRC}/bam -n -a -v ${_MAKE_JOBS:C/-j/-j /} ${BAM_TARGET}

do-install:
.if ! ${PORT_OPTIONS:MSERVER_ONLY}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}_srv ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/other/icons/Teeworlds.ico ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
