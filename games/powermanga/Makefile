# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	powermanga
PORTVERSION=	0.93.1
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade 2D shoot-em-up

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf localbase sdl tar:tgz xorg
USE_XORG=	xext xxf86dga
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes

PORTDOCS=	*
PORTDATA=	*

LIBS+=		-lm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS/ { s|-O3||; s|-Werror||; }' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's|/usr/share/games/powermanga|${DATADIR}|;s|/sound|&s|' \
		${WRKSRC}/powermanga.6
	@${REINPLACE_CMD} -e 's|\((prefix)\)/games|\1/bin|' \
		${WRKSRC}/src/Makefile.am
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e \
		'/pkgdatadir/ s|games/powermanga|powermanga|'
	@${REINPLACE_CMD} -e 's|games/powermanga|powermanga|' \
		${WRKSRC}/src/tools.c
	@${REINPLACE_CMD} -e 's|Lang=fr|Lang=en|' ${WRKSRC}/texts/config.ini

post-install:
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/powermanga.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/powermanga.xpm ${STAGEDIR}${PREFIX}/share/pixmaps/
.for f in powermanga.hi powermanga.hi-easy powermanga.hi-hard
	${MV} ${STAGEDIR}/var/games/${PORTNAME}/${f} ${STAGEDIR}/var/games/${PORTNAME}/${f}.sample
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
