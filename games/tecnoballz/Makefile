# New ports collection makefile for:	tecnoballz
# Date created:			19 Jan 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		tecnoballz
PORTVERSION=		0.90
CATEGORIES=		games
MASTER_SITES=		http://linux.tlk.fr/games/TecnoballZ/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A brick breaker (Arkanoid-like game)

LIB_DEPENDS=		mikmod.2:${PORTSDIR}/audio/libmikmod

WRKSRC=			${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=		${WRKSRC}/src

USE_X_PREFIX=		yes
USE_SDL=		sdl mixer
USE_GMAKE=		yes
USE_REINPLACE=		yes

MAN6=			tecnoballz.6

MAKE_ENV+=		LIBMIKMOD_CONFIG=${LOCALBASE}/bin/libmikmod-config

post-extract:
	@${RM} -f \
		${WRKSRC}/src/TecnoballZ/hires/.xvpics/*.bmp \
		${WRKSRC}/src/TecnoballZ/lores/.xvpics/*.bmp
	@${RMDIR} \
		${WRKSRC}/src/TecnoballZ/hires/.xvpics \
		${WRKSRC}/src/TecnoballZ/lores/.xvpics \

post-patch:
	@${FIND} ${WRKSRC}/include -name '*.h' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|SDL/||'
	@${REINPLACE_CMD} -e \
		's|/var/lib/games|/var/games|; \
		 s|TecnoballZ/|${DATADIR}/|' \
		${WRKSRC}/src/ressources.cc

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/tecnoballz ${PREFIX}/bin
	${CHGRP} games ${PREFIX}/bin/tecnoballz
	${CHMOD} g+s ${PREFIX}/bin/tecnoballz

	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/src/TecnoballZ/* ${DATADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	${CHMOD} 0644 ${DATADIR}/textures/*

	${MKDIR} ${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/man/tecnoballz.1 ${MAN6PREFIX}/man/man6/tecnoballz.6

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
