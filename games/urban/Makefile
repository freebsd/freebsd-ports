# New ports collection makefile for:	urban
# Date created:			25 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		urban
PORTVERSION=		1.5.2
CATEGORIES=		games
MASTER_SITES=		http://urban.worldonline.nl/files/linux/
DIST_SUBDIR=		urban

MAINTAINER=		jylefort@brutele.be
COMMENT=		A bloody, violent sidescrolling shoot-em-up

LIB_DEPENDS=		ggi:${PORTSDIR}/graphics/libggi \
			mikmod:${PORTSDIR}/audio/libmikmod

SCOREFILE=		/var/games/urban.scores

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=		--with-global-highscore=${SCOREFILE}

OPTIONS=		CHEAT_CODES "Enable cheat codes" off

.include <bsd.port.pre.mk>

.if defined(WITH_CHEAT_CODES)
CONFIGURE_ARGS+=	--enable-cheat-codes
.endif

post-install:
	${TOUCH} ${SCOREFILE}
	${CHGRP} games ${SCOREFILE}
	${CHMOD} g+w ${SCOREFILE}
	${CHGRP} games ${PREFIX}/bin/urban
	${CHMOD} g+s ${PREFIX}/bin/urban
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/CHEAT \
		${WRKSRC}/NEWS \
		${WRKSRC}/README \
		${WRKSRC}/README.swe \
		${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
