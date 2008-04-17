# New ports collection makefile for:	teewars
# Date created:		17 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	teeworlds
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	http://www.amdmi3.ru/distfiles/ \
		http://www.teeworlds.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} bam-${BAM_VERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Platform game featuring buggers equipped with weapons

USE_PYTHON_BUILD=	yes

BAM=	${WRKDIR}/bam.bin
BAM_VERSION=	20080326
BAM_TARGET=	release

OPTIONS=	TEEWORLDS_SERVER_ONLY	"Build dedicated server only"	off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
BROKEN=		Does not compile
.endif

.if defined(WITH_TEEWORLDS_SERVER_ONLY)
BAM_TARGET=	server_release
PLIST_SUB+=	CLIENT="@comment "
.else
LIB_DEPENDS+=	portaudio.2:${PORTSDIR}/audio/portaudio2
USE_XORG=	x11 xxf86vm
USE_GL=		yes
PLIST_SUB+=	CLIENT=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/default.bam
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/default.bam
	@${REINPLACE_CMD} -e 's|\(s.cc.c_compiler = \).*|\1"${CC}"|; \
		s|\(s.cc.cxx_compiler = \).*|\1"${CXX}"|; \
		s|\(s.cc.flags = \).*|\1"${CFLAGS}"|; \
		s|\(s.linker.linker = \).*|\1"${CXX}"|' \
		${WRKDIR}/bam/src/base.bam
	@${FIND} ${WRKSRC}/src -name "*.c" -o -name "*.cpp" | \
		${XARGS} ${REINPLACE_CMD} -e 's|"data/|"${DATADIR}/|g'
	@${REINPLACE_CMD} -e 's|"data/|"${DATADIR}/|g' ${WRKSRC}/datasrc/*

# build bam executable - teeworlds own build system
pre-build:
	cd ${WRKDIR}/bam && ${CC} ${CFLAGS} src/tools/txt2c.c -o src/tools/txt2c
	cd ${WRKDIR}/bam && src/tools/txt2c < src/base.bam > src/internal_base.h
	cd ${WRKDIR}/bam && ${CC} ${CFLAGS} src/lua/src/*.c src/lua/src/lib/*.c \
		src/*.c -Isrc/lua/include -o ${BAM} -lm ${PTHREAD_LIBS}

# build teeworlds
do-build:
	cd ${WRKSRC} && ${BAM} -v ${BAM_TARGET}

do-install:
.if !defined(WITH_TEEWORLDS_SERVER_ONLY)
	${INSTALL_PROGRAM} ${WRKSRC}/teeworlds ${PREFIX}/bin
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/teeworlds_srv ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}/

.include <bsd.port.post.mk>
