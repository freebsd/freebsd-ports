# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	pachi
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/dragontech/Pachi%20el%20marciano/Pachi%20el%20marciano%20${PORTVERSION}
DISTNAME=	pachi_source
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A platforms game similar to Manic Miner

USE_SDL=	mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/Pachi

SCOREDIR=	/var/games/pachi
SCOREFILE=	${SCOREDIR}/scores.dat

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/games/$$PACKAGE|${SCOREDIR}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|SCOREDIR[^,]*|"${SCOREFILE}"|' \
		${WRKSRC}/src/file.c
	@${REINPLACE_CMD} -e 's|:\ install-docDATA|:|' \
		${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e 's|install-scoreDATA\ install-data-local||' \
		${WRKSRC}/data/Makefile.in

post-install:
	${CHGRP} games ${PREFIX}/bin/pachi
	${CHMOD} g+s ${PREFIX}/bin/pachi
	${MKDIR} ${SCOREDIR}
.if !exists(${SCOREFILE})
	${INSTALL_DATA} ${WRKSRC}/data/scores.dat /var/games/pachi
.endif
	${CHGRP} -R games ${SCOREDIR}
	${CHMOD} g+w ${SCOREFILE}

.include <bsd.port.mk>
