# $FreeBSD$

PORTNAME=	chocolate-doom
PORTVERSION=	2.0.0
CATEGORIES=	games
MASTER_SITES=	http://www.chocolate-doom.org/downloads/2.0.0/

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Doom/Heretic/Hexen/Strife engine port compatible with the original exes

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_SDL=	mixer net sdl
USE_PYTHON=	2.5+
GNU_CONFIGURE=	yes

PORTDOCS=	CMDLINE.doom ChangeLog INSTALL.doom NEWS NOT-BUGS README README.OPL

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../doom-data/Makefile.include"

post-patch-script:
	${REINPLACE_CMD} -e 's|gamesdir = $$(prefix)/games|gamesdir = $$(prefix)/bin|' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/src/setup/Makefile.in

.include <bsd.port.mk>
