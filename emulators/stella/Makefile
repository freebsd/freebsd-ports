# New ports collection makefile for:   	stella
# Date created:			March 4, 1999
# Whom:				Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stella
PORTVERSION=	1.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes

PORTTOP=	${WRKDIR}/${PKGNAME}
WRKSRC=		${PORTTOP}/src/build
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd-x

USE_XLIB=	yes

DOCSDIR=	${PREFIX}/share/doc/stella
DOCS=		docs/stella.html
GFX=		docs/graphics/chucky_cheese.png \
		docs/graphics/circuit.png \
		docs/graphics/console.png \
		docs/graphics/jr_pacman.png \
		docs/graphics/pacman.png \
		docs/graphics/secret_quest.png \
		docs/graphics/space_invaders.png

post-build:
	@(cd ${PORTTOP}/src/ui/sound && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} oss)

do-install:
.for exe in src/build/stella.x11 src/ui/sound/stella-sound
	${INSTALL_PROGRAM} ${PORTTOP}/${exe} ${PREFIX}/bin/
.endfor
	${MKDIR} ${PREFIX}/share/stella
	${INSTALL_DATA} ${PORTTOP}/src/emucore/stella.pro \
		${PREFIX}/share/stella/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${PORTTOP}/${doc} ${DOCSDIR}/
.endfor
	${MKDIR} ${DOCSDIR}/graphics
.for gfx in ${GFX}
	${INSTALL_DATA} ${PORTTOP}/${gfx} ${DOCSDIR}/graphics/
.endfor
.endif

.include <bsd.port.mk>
