# New ports collection makefile for:	REminiscence
# Date created:		11 Feb 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	REminiscence
PORTVERSION=	0.1.8
CATEGORIES=	games
MASTER_SITES=	http://membres.lycos.fr/cyxdown/reminiscence/

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A rewritten engine for Flashback

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl

ALL_TARGET=	rs

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e '/^CXX =/ d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CXXFLAGS:=/ d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CXXFLAGS+=.*-W/ d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|DATA|${DATADIR}/data|' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${PREFIX}/bin/remin
	${MKDIR} ${DATADIR}/data

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
