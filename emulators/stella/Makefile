# New ports collection makefile for:   	stella
# Date created:			March 4, 1999
# Whom:				Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stella
PORTVERSION=	2.0.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-platform Atari 2600 VCS emulator

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GCC=	3.4+
USE_SDL=	sdl
USE_REINPLACE=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|sdlconfigs=.*$$|sdlconfigs=${SDL_CONFIG:T}|g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stella ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/emucore/stella.pro ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
