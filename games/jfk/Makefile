# New ports collection makefile for:	jfk
# Date created:				8 September 2002
# Whom:					Stefan Farfeleder <e0026813@stud3.tuwien.ac.at>
#
# $FreeBSD$
#

PORTNAME=	jfk
PORTVERSION=	0.1.1
CATEGORIES=	games
MASTER_SITES=	http://relax.ath.cx/jfk/

MAINTAINER=	e0026813@stud3.tuwien.ac.at

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

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

.include <bsd.port.mk>
