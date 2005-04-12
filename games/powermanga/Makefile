# New ports collection makefile for:	powermanga
# Date created:			26 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		powermanga
PORTVERSION=		0.79
PORTREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://linux.tlk.fr/games/Powermanga/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		An arcade 2D shoot-em-up

USE_X_PREFIX=		yes
USE_SDL=		sdl mixer
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--program-prefix=""
USE_REINPLACE=		yes

MAN6=			powermanga.6

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS="-O3.*||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/usr/share/games/\(powermanga/graphics\)|${PREFIX}/share/\1|; \
		 s|/usr/share/games/\(powermanga\)/sound|${PREFIX}/share/\1/sounds|' \
		${WRKSRC}/powermanga.6
	@${REINPLACE_CMD} -e 's|(mandir)|&/man6|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\((prefix)\)/games|\1/bin|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|games/\(powermanga\)|\1|' \
		${WRKSRC}/graphics/Makefile.in \
		${WRKSRC}/sounds/Makefile.in \
		${WRKSRC}/src/linuxroutines.cpp
	@${REINPLACE_CMD} -e 's|SDL/||' \
		${WRKSRC}/src/powermanga.hpp \
		${WRKSRC}/src/sdl_mixer.cpp

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/CHANGES \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
