# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	wargus
PORTVERSION=	2.4.1
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Warcraft 2 mod that allows you to play Warcraft 2 with Stratagus

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	stratagus:games/stratagus \
		ffmpeg2theora:multimedia/ffmpeg2theora \
		cdparanoia:audio/cdparanoia
BUILD_DEPENDS=	stratagus:games/stratagus
LIB_DEPENDS=	libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	Wargus

USES=		cmake compiler:c++11-lang gnome pkgconfig xorg
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DSHAREDIR:STRING="${DATADIR_REL}"
USE_XORG=	x11
USE_GNOME=	gtk20
SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
