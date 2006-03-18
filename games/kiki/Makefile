# New ports collection makefile for:	kiki
# Date created:		24 Oct 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	kiki
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Kiki the nanobot is a 3-D puzzle game

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_PYTHON=	2.3
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl mixer image
USE_DOS2UNIX=	yes
USE_GCC=	3.4+

MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

WRKSRC=		${WRKDIR}/kiki

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-kodilib-src-types-kvector.h
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|.*|CXXFLAGS+=$$(KODI_INCLUDES) -I${X11BASE}/include `${SDL_CONFIG} --cflags`|' ${WRKSRC}/kodilib/linux/Makefile
	@${REINPLACE_CMD} -e '/^X11_INCLUDES/ s|/.*/|${X11BASE}/include|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e '/PYTHON/ s|/usr|${LOCALBASE}|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|CXXFLAGS =|CXXFLAGS +=|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|PYTHON_VERSION|PYTHON_VER|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e '/^GLLIBS/ s|$$| -L${X11BASE}/lib|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|getenv("KIKI_HOME")|"${DATADIR}"|' ${WRKSRC}/src/main/KikiController.cpp

do-build:
	@cd ${WRKSRC}/kodilib/linux && ${SETENV} ${MAKE_ENV} ${GMAKE}
	@cd ${WRKSRC}/linux && ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/kiki ${PREFIX}/bin
.for d in py sound
	@cd ${WRKSRC}/${d} && \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/${d}/{} \; ;\
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/${d}/{} \;
.endfor

.include <bsd.port.post.mk>
