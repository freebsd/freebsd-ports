# New ports collection makefile for: OpenGL headers for Mingw32
# Date created:	29 Dec 2001
# Whom:		Michal Pasternak <doc@lublin.t1.pl>
#
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	20011229
CATEGORIES=	devel graphics
MASTER_SITES=	ftp://ftp.microsoft.com/softlib/mslfiles/
PKGNAMEPREFIX=	mingw-
PKGNAMESUFFIX=	-headers
DISTNAME=	opengl95
EXTRACT_SUFX=	.exe
DIST_SUBDIR=	mingw

MAINTAINER=	doc@lublin.t1.pl

BUILD_DEPENDS=	mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt

RESTRICTED=	"Not sure if we can redistribute it"

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${PREFIX}/i386-mingw32msvc/include/GL
	${LN} -s ${PREFIX}/i386-mingw32msvc/include/GL ${PREFIX}/i386-mingw32msvc/include/gl
	${CP} ${WRKSRC}/INCLUDE/GL/GL.H ${PREFIX}/i386-mingw32msvc/include/GL/gl.h
	${CP} ${WRKSRC}/INCLUDE/GL/GLAUX.H ${PREFIX}/i386-mingw32msvc/include/GL/glaux.h
	${CP} ${WRKSRC}/INCLUDE/GL/GLU.H ${PREFIX}/i386-mingw32msvc/include/GL/glu.h
	${CP} ${WRKSRC}/DLL/GLU32.DLL ${PREFIX}/i386-mingw32msvc/lib/glu32.dll
	${CP} ${WRKSRC}/DLL/OPENGL32.DLL ${PREFIX}/i386-mingw32msvc/lib/opengl32.dll

.include <bsd.port.mk>
