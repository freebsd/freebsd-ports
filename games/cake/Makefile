# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	cake
PORTVERSION=	2005.12.26
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake3 map viewer (and powerful 3D game engine)

LICENSE=	GPLv2

USES=		gmake jpeg ncurses zip
USE_GL=		glut
USE_XORG=	x11 xext xmu xt xi sm ice

# Need to pass `-l', but PATCH_ARGS+= won't work because of PATCH_ARGS?=
# in bsd.port.mk
PATCH_ARGS=	-N -s -E ${PATCH_STRIP} -l

ALL_TARGET=	main
WRKSRC=		${WRKDIR}/cake_src

PLIST_FILES=	bin/cake

post-patch: .SILENT
	${FIND} -E ${WRKDIR} -type f \( -iregex ".*\.(cpp|h)" -or \
		-name Makefile \) \
		-exec ${REINPLACE_CMD} -E -e 's/[[:cntrl:]]*$$//' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*push[[:blank:]]*,[[:blank:]]*1[[:blank:]]*\)/#pragma pack(1)/g' \
		-e 's/#pragma[[:blank:]]+pack[[:blank:]]*\([[:blank:]]*pop[[:blank:]]*\)/#pragma pack()/g' {} \;
	${REINPLACE_CMD} -e 's/jpeg\/JPEGLIB\.H/jpeglib.h/' \
		${WRKSRC}/cake/texture.cpp
# Fmod library is not supported on FreeBSD, so no sound :(
	${REINPLACE_CMD} -e 's/ENABLE_SOUND 1/ENABLE_SOUND 0/' \
		${WRKSRC}/cake/sound.h
# Use traditional mapping for console key (tilde)
	${REINPLACE_CMD} -e 's/167/96/' ${WRKSRC}/main.cpp
# Fix for GCC 4.x
	${REINPLACE_CMD} -e 's/Mat3x2:://' ${WRKSRC}/cake/math.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main ${STAGEDIR}${PREFIX}/bin/cake

.include <bsd.port.mk>
