# New ports collection makefile for:	gltron
# Version required:			0.53
# Date created:				24 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	gltron-0.53
CATEGORIES=	games
MASTER_SITES=	http://www.ards.net/Andreas/gltron/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3 \
		GLU.14:${PORTSDIR}/graphics/Mesa3 \
		glut.3:${PORTSDIR}/graphics/Mesa3

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV+=	OPT="${CFLAGS}"

do-install:
	@${MKDIR} ${PREFIX}/share/gltron/
.for FILE in *.sgi *.txt t-u-low.obj tron.mtl xenotron.ftx
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/gltron/
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/gltron ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gltron
.for file in CHANGELOG CREDITS README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gltron
.endfor
.endif

.include <bsd.port.mk>
