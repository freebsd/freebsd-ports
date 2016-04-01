# $FreeBSD$

PORTNAME=	chocolate-doom
PORTVERSION=	2.2.1
CATEGORIES=	games
MASTER_SITES=	http://www.chocolate-doom.org/downloads/${PORTVERSION}/

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Doom/Heretic/Hexen/Strife engine port compatible with the originals

LICENSE=	GPLv2

BUILD_DEPENDS=	python:lang/python

USES=		gmake
USE_SDL=	mixer net sdl
GNU_CONFIGURE=	yes

PORTDOCS=	CMDLINE.doom ChangeLog INSTALL.doom NEWS NOT-BUGS PHILOSOPHY \
		README README.Music

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../doom-data/Makefile.include"

post-patch:
	${REINPLACE_CMD} -e 's|gamesdir = $${exec_prefix}/games|gamesdir = $${exec_prefix}/bin|' \
		${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's|gamesdir = $$(prefix)/games|gamesdir = $$(prefix)/bin|' \
		${WRKSRC}/src/setup/Makefile.in
post-install:
	  ${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chocolate-*

.include <bsd.port.mk>
