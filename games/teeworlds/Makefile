# New ports collection makefile for:	teewars
# Date created:		17 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	teeworlds
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	http://www.teeworlds.com/files/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} bam-${BAM_VERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Platform game featuring buggers equipped with weapons

USE_PYTHON_BUILD=	yes

BAM_VERSION=	0.2.0
BAM_WRKSRC=	${WRKDIR}/bam-${BAM_VERSION}
BAM_TARGET=	release
MAKE_JOBS_SAFE=	yes

OPTIONS=	TEEWORLDS_SERVER_ONLY	"Build dedicated server only"	off

.include <bsd.port.pre.mk>

.if defined(WITH_TEEWORLDS_SERVER_ONLY)
BAM_TARGET=	server_release
PLIST_SUB+=	CLIENT="@comment "
.else
USE_XORG=	x11
USE_GL=		gl glu
USE_SDL=	sdl
PLIST_SUB+=	CLIENT=""
DESKTOP_ENTRIES="Teeworlds" \
		"Platform game featuring buggers equipped with weapons" \
		"${DATADIR}/Teeworlds.ico" \
		"teeworlds" \
		"Game;ActionGame;" \
		false
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O.||; s|-lpthread|${PTHREAD_LIBS}|; s|^gcc|${CC} ${CFLAGS}|' \
		${BAM_WRKSRC}/make_unix.sh
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/other/sdl/sdl.bam
	@${REINPLACE_CMD} -e '/sdirs\[\]/,/}/ s|"/.*"|"${DATADIR}"|' \
		${WRKSRC}/src/engine/e_engine.c

	@${REINPLACE_CMD} -e 's|\(settings.cc.c_compiler = \).*|\1"${CC}"|; \
		s|\(settings.cc.cxx_compiler = \).*|\1"${CXX}"|' \
		${BAM_WRKSRC}/src/driver_gcc.bam
	@${REINPLACE_CMD} -e 's|\(settings.*linker = \).*|\1"${CXX}"|' \
		${BAM_WRKSRC}/src/base.bam
	@${REINPLACE_CMD} -e '/settings.cc.flags:Add/ s|-fno-exceptions|& ${CFLAGS}|' \
		${WRKSRC}/default.bam

# build bam executable - teeworlds own build system
pre-build:
	cd ${BAM_WRKSRC} && ${SH} -v make_unix.sh

# build teeworlds
do-build:
	cd ${WRKSRC} && ${BAM_WRKSRC}/src/bam ${_MAKE_JOBS:C/-j/-j /} -v ${BAM_TARGET}

do-install:
.if !defined(WITH_TEEWORLDS_SERVER_ONLY)
	${INSTALL_PROGRAM} ${WRKSRC}/teeworlds ${PREFIX}/bin
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/teeworlds_srv ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/other/icons/Teeworlds.ico ${DATADIR}

.include <bsd.port.post.mk>
