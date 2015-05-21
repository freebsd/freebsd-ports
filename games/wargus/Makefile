# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	wargus
PORTVERSION=	2.3.0
CATEGORIES=	games
MASTER_SITES=	http://launchpadlibrarian.net/200671642/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Warcraft 2 mod that allows you to play Warcraft 2 with Stratagus

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	stratagus:${PORTSDIR}/games/stratagus \
		ffmpeg2theora:${PORTSDIR}/multimedia/ffmpeg2theora \
		cdparanoia:${PORTSDIR}/audio/cdparanoia
BUILD_DEPENDS=	stratagus:${PORTSDIR}/games/stratagus
LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USES=		cmake pkgconfig
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DSHAREDIR:STRING="${DATADIR_REL}"
USE_X11=	x11
USE_GNOME=	gtk20
SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900000
BROKEN=		does not build
.endif

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
