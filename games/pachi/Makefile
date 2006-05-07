# New ports collection makefile for:	pachi
# Date created:		18 Sep 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	pachi
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dragontech
DISTNAME=	pachi_source
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A platforms game similar to Manic Miner

USE_SDL=	mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" CXX="${CXX}"

WRKSRC=		${WRKDIR}/Pachi

SCOREDIR=	/var/games/pachi
SCOREFILE=	${SCOREDIR}/scores.dat

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/src/faes.cpp
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
