# New ports collection makefile for:	sdlCC
# Date created:		21 November 2007
# Whom:			Frank W. Josellis <frank@dynamical-systems.org>
#
# $FreeBSD$
#

PORTNAME=	sdlCC
PORTVERSION=	0.0.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://chinesecheckers.vegard2.no/ \
		http://jcatki.no-ip.org/files/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	An extensible chinese checkers game using SDL

USE_AUTOTOOLS=	libtool:15
USE_SDL=	image mixer sdl
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure ${WRKSRC}/libltdl/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/players/README ${DOCSDIR}/README.players
.endif

.include <bsd.port.mk>
