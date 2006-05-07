# New ports collection makefile for:	Cake
# Date created:				28 July 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	cake
PORTVERSION=	2005.12.26
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.calodox.scene.org/morbac/cake/download/ \
		${MASTER_SITE_LOCAL} http://freebsd.nsu.ru/distfiles/
MASTER_SITE_SUBDIR=	danfe
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake3 map viewer

.if defined(WITH_FREEGLUT)
LIB_DEPENDS=	glut.11:${PORTSDIR}/graphics/freeglut
.else
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut
.endif
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg

# Need to pass `-l', but PATCH_ARGS+= won't work because of PATCH_ARGS?=
# in bsd.port.mk.
PATCH_ARGS=	-d ${PATCH_WRKSRC} -N -s -E ${PATCH_STRIP} -l
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_ZIP=	yes

ALL_TARGET=	main
MAKE_ARGS+=	CXX=${CXX} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=		${WRKDIR}/cake_src

PLIST_FILES=	bin/cake

pre-everything::
.if !defined(WITH_FREEGLUT)
	@${ECHO_MSG} "Define WITH_FREEGLUT to build against FreeGLUT"
.endif

post-extract:
	@${FIND} -E ${WRKDIR} -type f \( -iregex ".*\.(cpp|h)" -or -name Makefile \) \
		-exec ${REINPLACE_CMD} -E -e 's/[[:cntrl:]]*$$//' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*push[[:blank:]]*,[[:blank:]]*1[[:blank:]]*\)/#pragma pack(1)/g' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*pop[[:blank:]]*\)/#pragma pack()/g' '{}' \;
	@${REINPLACE_CMD} -e 's/ENABLE_SOUND 1/ENABLE_SOUND 0/' \
		${WRKSRC}/cake/sound.h
	@${REINPLACE_CMD} -e 's/167/96/' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main ${PREFIX}/bin/cake

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
