# Created by: Stefan Farfeleder <e0026813@stud3.tuwien.ac.at>
# $FreeBSD$

PORTNAME=	jfk
PORTVERSION=	0.1.1
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://hop.at/jfk/

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiplayer 2D shoot'em up game

USE_SDL=	image sdl
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/client/jfkclient ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/server/jfkserver ${PREFIX}/bin
.for file in art levels
	@(cd ${WRKSRC}/${file}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install)
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in controls.txt jfkclient.sample jfkserver.sample
	${INSTALL_MAN} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
