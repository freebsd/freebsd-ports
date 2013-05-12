# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	fuhquake
PORTVERSION=	0.31
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.fuhquake.net/files/releases/v${PORTVERSION}/ \
		http://www.fuhquake.net/files/misc/:misc
DISTNAME=	${PORTNAME}-source-v${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-linux-v${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Excellent and feature-rich QuakeWorld client

DEPRECATED=	Upstream disappeared; no more distfiles

USE_ZIP=	yes
MAKEFILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}/source

DATADIR=	${Q1DIR}
MAKE_ENV=	DATADIR="${DATADIR}"

OPTIONS_DEFINE=		HUD OPTIMIZED_CFLAGS XMMS DOCS
OPTIONS_MULTI=		CLIENT
OPTIONS_MULTI_CLIENT=	GLX X11
OPTIONS_DEFAULT=	GLX OPTIMIZED_CFLAGS X11 DOCS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM

CLIENT_DESC=	Clients
GLX_DESC=	Build GLX client
X11_DESC=	Build X11 client
HUD_DESC=	Install high quality HUD images
XMMS_DESC=	Enable MP3 player feature

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLX}
USE_GL=		yes
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg
CFLAGS+=	-I${LOCALBASE}/include/libpng15
PLIST_SUB+=	GLX=""
CLIENTS+=	glx
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xxf86dga
PLIST_SUB+=	X11=""
CLIENTS+=	x11
.else
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MHUD}
DISTFILES+=	fuh-hud${EXTRACT_SUFX}:misc
PLIST_SUB+=	HUD=""
.else
PLIST_SUB+=	HUD="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ARGS+=	-DWITH_OPTIMIZED_CFLAGS
.endif

.if ! ${PORT_OPTIONS:MASM}
MAKE_ARGS+=	-DWITHOUT_X86_ASM
.endif

.if ${PORT_OPTIONS:MXMMS} || exists(${LOCALBASE}/lib/libxmms.so.4)
LIB_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
MAKE_ARGS+=	-DWITH_XMMS \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}
.endif

post-patch:
	@${CP} ${FILESDIR}/*.c ${WRKSRC}

do-build:
.for f in ${CLIENTS}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean ${f})
.endfor

do-install:
.for f in ${CLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/qw/*.dat ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/pak0.pak ${DATADIR}/${PORTNAME}
.if ${PORT_OPTIONS:MHUD}
	@${MKDIR} ${DATADIR}/${PORTNAME}/textures/wad
	${INSTALL_DATA} ${WRKDIR}/qw/charset.png ${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/qw/textures/wad/* \
		${DATADIR}/${PORTNAME}/textures/wad
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
