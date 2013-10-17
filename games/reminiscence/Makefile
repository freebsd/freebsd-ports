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
USES=		gmake
USE_SDL=	sdl

ALL_TARGET=	rs

SUB_FILES=	pkg-message

PORTDOCS=	README

PLIST_FILES=	bin/remin
PLIST_DIRSTRY=	%%DATADIR%%/data %%DATADIR%%

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|DATA|${DATADIR}/data|' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${STAGEDIR}${PREFIX}/bin/remin
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
