# New ports collection makefile for:	Cake
# Date created:				28 July 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	cake
PORTVERSION=	2005.12.26
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.calodox.scene.org/morbac/cake/download/ \
		${MASTER_SITE_LOCAL} http://freebsd.nsu.ru/distfiles/
MASTER_SITE_SUBDIR=	danfe
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake3 map viewer

# Need to pass `-l', but PATCH_ARGS+= won't work because of PATCH_ARGS?=
# in bsd.port.mk.
PATCH_ARGS=	-d ${PATCH_WRKSRC} -N -s -E ${PATCH_STRIP} -l
USE_GMAKE=	yes
USE_ZIP=	yes

ALL_TARGET=	main
MAKE_ARGS+=	CXX=${CXX} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=		${WRKDIR}/cake_src

PLIST_FILES=	bin/cake

OPTIONS=	FREEGLUT "Build with alternative GLUT library, FreeGLUT" off

.include <bsd.port.pre.mk>

.if defined(WITH_FREEGLUT)
LIB_DEPENDS=	glut.11:${PORTSDIR}/graphics/freeglut
.else
USE_GL=		glut
.endif
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg

post-patch: .SILENT
	${FIND} -E ${WRKDIR} -type f \( -iregex ".*\.(cpp|h)" -or \
		-name Makefile \) \
		-exec ${REINPLACE_CMD} -E -e 's/[[:cntrl:]]*$$//' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*push[[:blank:]]*,[[:blank:]]*1[[:blank:]]*\)/#pragma pack(1)/g' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*pop[[:blank:]]*\)/#pragma pack()/g' '{}' \;
	${REINPLACE_CMD} -e 's/ENABLE_SOUND 1/ENABLE_SOUND 0/' \
		${WRKSRC}/cake/sound.h
	${REINPLACE_CMD} -e 's/167/96/' ${WRKSRC}/main.cpp
# Fix for GCC 4.x
	${REINPLACE_CMD} -e 's/Mat3x2:://' ${WRKSRC}/cake/math.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main ${PREFIX}/bin/cake

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
