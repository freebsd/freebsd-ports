# New ports collection makefile for:   	stella
# Date created:			March 4, 1999
# Whom:				Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stella
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src/build

USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKEFILE=	makefile
ALL_TARGET=	freebsd-x

DOCS=		docs/stella.html
GFX=		docs/graphics/chucky_cheese.png \
		docs/graphics/circuit.png \
		docs/graphics/console.png \
		docs/graphics/jr_pacman.png \
		docs/graphics/pacman.png \
		docs/graphics/secret_quest.png \
		docs/graphics/space_invaders.png

post-build:
	@(cd ${WRKSRC}/src/ui/sound && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} oss)

do-install:
.for exe in src/build/stella.x11 src/ui/sound/stella-sound
	${INSTALL_PROGRAM} ${WRKSRC}/${exe} ${PREFIX}/bin/
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/emucore/stella.pro ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
	${MKDIR} ${DOCSDIR}/graphics
.for gfx in ${GFX}
	${INSTALL_DATA} ${WRKSRC}/${gfx} ${DOCSDIR}/graphics/
.endfor
.endif

.include <bsd.port.mk>
