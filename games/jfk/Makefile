# New ports collection makefile for:	jfk
# Date created:				8 September 2002
# Whom:					Stefan Farfeleder <e0026813@stud3.tuwien.ac.at>
#
# $FreeBSD$
#

PORTNAME=	jfk
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://relax.ath.cx/jfk/

MAINTAINER=	stefan@fafoe.narf.at
COMMENT=	A multiplayer 2D shoot'em up game

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
USE_SDL=	image sdl

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
	@${SED} s-\$${PREFIX}-${PREFIX}-g < ${PKGMESSAGE}

.include <bsd.port.post.mk>
