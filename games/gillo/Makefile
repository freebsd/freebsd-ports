# Created by: Igor Pokrovsky <ip@doom.homeunix.org>

PORTNAME=	gillo
DISTVERSION=	1.0beta1
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta1
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Players are cars throwing a magnetic fuzzy ball into a goal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${JAM}:devel/jam \
		${LOCALBASE}/lib/libplibsg.a:x11-toolkits/plib
LIB_DEPENDS=	libode.so:devel/ode

USES=		gl sdl tar:bzip2
USE_CXXSTD=	c++98
USE_GL=		gl glu
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${PORTNAME}

JAM?=		${LOCALBASE}/bin/jam

post-patch:
	@${REINPLACE_CMD} '/^LINKLIBS on gillo3/s|;$$|-L${LOCALBASE}/lib -lm ;|' \
		${WRKSRC}/src/Jamfile

do-build:
	cd ${WRKSRC} && ${SETENV} C++="${CXX}" C++FLAGS="${CXXFLAGS}" \
		CCFLAGS="${CFLAGS} -DDATADIR=\\\"${PREFIX}/share\\\"" \
		HDRS="${LOCALBASE}/include" \
		LINK="${CXX}" LINKFLAGS="${LDFLAGS}" \
		${JAM} -dx -sPREFIX=${PREFIX}

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} gillo3 ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data && ${INSTALL_DATA} *.* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
