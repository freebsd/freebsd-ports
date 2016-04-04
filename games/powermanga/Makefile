# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	powermanga
PORTVERSION=	0.93.1
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade 2D shoot-em-up

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf
USE_XORG=	xext xxf86dga
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes

PORTDOCS=	*
PORTDATA=	*

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lm

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
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/powermanga.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/powermanga.xpm ${STAGEDIR}${PREFIX}/share/pixmaps/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
.for f in powermanga.hi powermanga.hi-easy powermanga.hi-hard
	${MV} ${STAGEDIR}/var/games/${PORTNAME}/${f} ${STAGEDIR}/var/games/${PORTNAME}/${f}.sample
.endfor

.include <bsd.port.mk>
