# New ports collection makefile for:	egl
# Date created:				20 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	egl
PORTVERSION=	0.2.5
CATEGORIES=	games
MASTER_SITES=	http://egl.quakedev.com/files/:src \
		ftp://ftp.alepulver.com.ar/ports/egl/:data
DISTNAME=	${PORTNAME}-v${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		egl.pkz:data
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhaced OpenGL only Quake II engine

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

MAKEFILE=	makefile

MAKE_ENV=	LIBDIR="${LIBDIR}" PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DEDICATED)
PLIST_SUB+=	DEDICATED=""
.else
MAKE_ENV+=	BUILD_DEDICATED=NO
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	WITH_OPT_CFLAGS=NO
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/egl ${PREFIX}/bin
.if !defined(WITHOUT_DEDICATED)
	${INSTALL_PROGRAM} ${WRKSRC}/release/eglded ${PREFIX}/bin
.endif
	${MKDIR} ${LIBDIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/release/baseq2/*.so ${LIBDIR}/baseq2
	${INSTALL_DATA} ${DISTDIR}/egl.pkz ${LIBDIR}/baseq2

.include <bsd.port.post.mk>
