# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	REminiscence
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://cyxdown.free.fr/reminiscence/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A rewritten engine for Flashback

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl

ALL_TARGET=	rs

SUB_FILES=	pkg-message

PORTDOCS=	README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|DATA|${DATADIR}/data|' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${PREFIX}/bin/remin
	${MKDIR} ${DATADIR}/data
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
