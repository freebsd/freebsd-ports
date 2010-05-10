# New ports collection makefile for:	deng
# Date created:		25 Aug 2004
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	deng
PORTVERSION=	1.9.0b6.9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Doomsday%20Engine/1.9.0-beta6.9
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/-beta/}

MAINTAINER=	yuri.pankov@gmail.com
COMMENT=	An enhanced Doom, Heretic and Hexen source port

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_SDL=	sdl mixer net
USE_XORG=	x11
USE_PYTHON=	yes

BUILDDIR=	${WRKSRC}/doomsday/portbuild
BUILD_WRKSRC=	${BUILDDIR}
INSTALL_WRKSRC=	${BUILDDIR}

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS:STRING="-Wl,--export-dynamic"

MAN6=		doomsday.6

OPTIONS=	OPENAL "Build OpenAL sound plugin" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPENAL) || exists(${LOCALBASE}/lib/libopenal.so)
USE_OPENAL=	al
CMAKE_ARGS+=	-DBUILDOPENAL:BOOL=ON
PLIST_SUB=	OPENAL=""
.else
PLIST_SUB=	OPENAL="@comment "
.endif

post-patch:
	${REINPLACE_CMD} \
		-e '/CHECK_LIBRARY_EXIST/s/dl//' \
		-e '/TARGET_LINK_LIBRARIES/s/dl//' \
		${WRKSRC}/doomsday/CMakeLists.txt

do-configure:
	@${MKDIR} ${BUILDDIR}
	@cd ${BUILDDIR}; ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ..

post-install:
	@${LN} -s ${PREFIX}/bin/doomsday ${PREFIX}/bin/deng
	${INSTALL_MAN} ${WRKSRC}/doomsday/engine/doc/doomsday.6 ${MANPREFIX}/man/man6/
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in LICENSE changelog.txt cnsname.txt cvars.txt deddoc.txt dhistory.txt naming.txt network.txt
	${INSTALL_DATA} ${WRKSRC}/doomsday/engine/doc/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
