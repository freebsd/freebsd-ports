# New ports collection makefile for: OpenGL headers for Mingw32
# Date created:	29 Dec 2001
# Whom:		Michal Pasternak <doc@lublin.t1.pl>
#
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	20011229
CATEGORIES=	devel graphics
MASTER_SITES=	ftp://ftp.unina.it/pub/pcibm/microsoft/MSLFILES/ \
		ftp://ftp.clinet.fi/.3/ftp.microsoft.com/Softlib/MSLFILES/ \
		ftp://ftp.task.gda.pl/mirror/ftp.cdrom.com/pub/idgames2/telefragged/gamedesign/rust/quake2/level_editors/patches_utilities/ \
		ftp://ftp.esan.inet.co.th/pub/DRIVERS/VGA/AGP/3DLABS/PERMEDIA/WIN95/ \
		ftp.unina.it/pub/Pcibm/microsoft/MSLFILES/ \
		ftp.cyf-kr.edu.pl/pub/mirror/Microsoft/SoftLib/MSLFILES/ \
		ftp.wiwi.uni-marburg.de/pub/mirror/ftp.microsoft.com/Softlib/MSLFILES/ \
		ftp.demon.net/pub/mirrors/idgames/telefragged/gamedesign/rust/quake2/level_editors/patches_utilities/ \
		ftp.utbm.fr/pub/pc/microsoft/Softlib/MSLFILES/ \
		ftp.ntua.gr/pub/pc/microsoft/softlib/MSLFILES/
PKGNAMEPREFIX=	mingw-
PKGNAMESUFFIX=	-headers
DISTNAME=	OPENGL95
EXTRACT_SUFX=	.EXE
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
