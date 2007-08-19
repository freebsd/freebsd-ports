# New ports collection makefile for:	memonix
# Date created:		12 Jul 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	memonix
PORTVERSION=	1.6.070713
CATEGORIES=	games
MASTER_SITES=	http://www.viewizard.com/download/ \
		http://www.amdmi3.ru/distfiles/
DISTNAME=	MemonixSourceCode_${PORTVERSION:S/./_/g:S/_/./}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} memx16.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Brain teasers, puzzle and memory games for kids in one pack

BUILD_DEPENDS=	${CMAKE}:${PORTSDIR}/devel/cmake

CMAKE?=		${LOCALBASE}/bin/cmake

USE_ZIP=	yes
USE_SDL=	sdl mixer image
USE_GL=		yes

CMAKE_DEFS=	-DCMAKE_EXE_LINKER_FLAGS:STRING="${LINKERFLAGS} ${PTHREAD_LIBS}" \
		-DCMAKE_THREAD_LIBS:STRING="${PTHREAD_LIBS}"\
		-DCMAKE_USE_PTHREADS:BOOL=ON \
		-DCMAKE_C_COMPILER:STRING="${CC}" \
		-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS} ${PTHREAD_CFLAGS}"

WRKSRC=		${WRKDIR}/MemonixSourceCode

PLIST_FILES=	bin/Memonix %%DATADIR%%/gamedata.vfs
PLIST_DIRS=	%%DATADIR%%

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${DISTDIR}/memx16.tar.gz

post-patch:
	@${REINPLACE_CMD} -e '/strcpy(ProgrammDir,/ s|\./|${DATADIR}/|' \
		 ${WRKSRC}/src/Main.cpp

do-configure:
	cd ${WRKSRC} && ${CMAKE} . ${CMAKE_DEFS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Memonix ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/Memonix/gamedata.vfs ${DATADIR}

.include <bsd.port.mk>
