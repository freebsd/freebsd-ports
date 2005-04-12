# New ports collection makefile for:	urban
# Date created:			25 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		urban
PORTVERSION=		1.5.3
PORTREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://urban.bengburken.net/files/linux/
DIST_SUBDIR=		urban

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A bloody, violent sidescrolling shoot-em-up

LIB_DEPENDS=		ggi:${PORTSDIR}/graphics/libggi \
			mikmod:${PORTSDIR}/audio/libmikmod

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=		--with-global-highscore=/var/games/urban.scores

OPTIONS=		CHEAT_CODES "Enable cheat codes" off

.include <bsd.port.pre.mk>

.if defined(WITH_CHEAT_CODES)
CONFIGURE_ARGS+=	--enable-cheat-codes
.endif

post-install:
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
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
