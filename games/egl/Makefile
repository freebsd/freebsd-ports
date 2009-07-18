# New ports collection makefile for:	egl
# Date created:				20 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	egl
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://egl.quakedev.com/files/:src \
		ftp://ftp.alepulver.com.ar/distfiles/:data
DISTNAME=	${PORTNAME}-v${PORTVERSION}-stable-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		egl.pkz:data
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhaced OpenGL only Quake II engine

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		GAME "Build main game modification" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

MAKEFILE=	makefile

MAKE_ENV=	LIBDIR="${LIBDIR}" PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_CLIENT)
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
USE_GL=		yes
PLIST_SUB+=	CLIENT=""
EGL_BIN+=	egl
.else
MAKE_ENV+=	BUILD_CLIENT=NO \
		BUILD_CGAME=NO
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_DEDICATED)
PLIST_SUB+=	DEDICATED=""
EGL_BIN+=	eglded
.else
MAKE_ENV+=	BUILD_DEDICATED=NO
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAME)
PLIST_SUB+=	GAME=""
.else
MAKE_ENV+=	BUILD_GAME=NO
PLIST_SUB+=	GAME="@comment "
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	WITH_OPT_CFLAGS=NO
.endif

do-install:
.for f in ${EGL_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/release/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${LIBDIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/release/baseq2/*.so ${LIBDIR}/baseq2
	${INSTALL_DATA} ${DISTDIR}/egl.pkz ${LIBDIR}/baseq2

.include <bsd.port.post.mk>
