# New ports collection makefile for:   	stella
# Date created:			March 4, 1999
# Whom:				Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stella
PORTVERSION=	1.4.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-platform Atari 2600 VCS emulator

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src/build

USE_GNOME=	pkgconfig
USE_SDL=	sdl
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" LD="${CXX}" OPTIMIZATIONS="${CXXFLAGS}" \
		SYS_INCLUDES="${CPPFLAGS}" LDFLAGS="" LDLIBS="${LDFLAGS}"
ALL_TARGET=	linux-gl

CPPFLAGS=	`${SDL_CONFIG} --cflags` `pkg-config --cflags libpng12` \
		-I${X11BASE}/include
LDFLAGS=	`${SDL_CONFIG} --libs` `pkg-config --libs libpng12` \
		-L${X11BASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/build/stella ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/emucore/stella.pro ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
