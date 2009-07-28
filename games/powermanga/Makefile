# New ports collection makefile for:	powermanga
# Date created:			26 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	powermanga
PORTVERSION=	0.90
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An arcade 2D shoot-em-up

USE_XORG=	xext xxf86dga
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS CHANGES

MAN6=		powermanga.6

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS="-O3.*|CFLAGS="$$CFLAGS -std=c99"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/usr/share/games/powermanga|${DATADIR}|;s|/sound|&s|' \
		${WRKSRC}/powermanga.6
	@${REINPLACE_CMD} -e 's|(mandir)|&/man6|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\((prefix)\)/games|\1/bin|' \
		${WRKSRC}/src/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|games/powermanga|powermanga|'
	@${REINPLACE_CMD} -e 's|games/powermanga|powermanga|' \
		${WRKSRC}/src/tools.c
	@${REINPLACE_CMD} -e 's|Lang=fr|Lang=en|' ${WRKSRC}/texts/config.ini

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${INSTALL_DATA} ${WRKSRC}/texts/config.ini ${DATADIR}/texts
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
