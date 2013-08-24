# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	powermanga
PORTVERSION=	0.91
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An arcade 2D shoot-em-up

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_XORG=	xext xxf86dga
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal automake autoconf autoheader

PORTDOCS=	AUTHORS CHANGES

MAN6=		powermanga.6

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

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

run-autotools:
	cd ${WRKSRC} && ${SH} ./bootstrap

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/powermanga.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/powermanga.xpm ${PREFIX}/share/pixmaps/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
