# New ports collection makefile for:	Cake
# Date created:				28 July 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	cake
PORTVERSION=	2004.07.09
CATEGORIES=	games
MASTER_SITES=	http://www.calodox.scene.org:8080/morbac/cake/download/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}_src

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Quake3 map viewer

.if defined(WITH_FREEGLUT)
LIB_DEPENDS=	glut.11:${PORTSDIR}/x11-toolkits/freeglut
.else
LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut
.endif
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_ZIP=	yes

ALL_TARGET=	main
MAKE_ARGS+=	PTHREAD_LIBS=${PTHREAD_LIBS}

PLIST_FILES=	bin/cake

pre-everything::
.if !defined(WITH_FREEGLUT)
	@${ECHO_MSG} "Define WITH_FREEGLUT to build against FreeGLUT"
.endif

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(cpp|h)" \
		-exec ${REINPLACE_CMD} -E -e 's/[[:cntrl:]]*$$//' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*push[[:blank:]]*,[[:blank:]]*1[[:blank:]]*\)/#pragma pack(1)/g' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*pop[[:blank:]]*\)/#pragma pack()/g' '{}' \;
	@${REINPLACE_CMD} -e 's/checkGLError/CheckGLError/g' \
		${WRKSRC}/cake/glsetup/glutils.cpp ${WRKSRC}/cake/q3bsp.cpp
	@${REINPLACE_CMD} -e 's/get_nstart_pos/GetNumStartPos/g' \
		-e 's/set_start_pos/SetStartPos/g' \
		-e 's/moveMouseXY/MoveMouseXY/g' \
		-e 's/moveForward/MoveForward/g' \
		-e 's/moveBackward/MoveBackward/g' \
		-e 's/moveRight/MoveRight/g' \
		-e 's/moveLeft/MoveLeft/g' \
		-e 's/moveUp/MoveUp/g' \
		-e 's/moveDown/MoveDown/g' \
		-e 's/report/Report/g' ${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's/ENABLE_SOUND 1/ENABLE_SOUND 0/' \
		${WRKSRC}/cake/sound.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main ${PREFIX}/bin/cake

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
