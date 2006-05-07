# New ports collection makefile for:	urban
# Date created:			25 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	urban
PORTVERSION=	1.5.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://urban.bengburken.net/files/linux/
DIST_SUBDIR=	urban

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A bloody, violent sidescrolling shoot-em-up

LIB_DEPENDS=	ggi:${PORTSDIR}/graphics/libggi \
		mikmod:${PORTSDIR}/audio/libmikmod

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DGG_NEED_OLD_INTTYPES" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-global-highscore=/var/games/urban.scores

PORTDOCS=	AUTHORS CHEAT NEWS README README.swe

OPTIONS=	CHEAT_CODES "Enable cheat codes" off

.include <bsd.port.pre.mk>

.if defined(WITH_CHEAT_CODES)
CONFIGURE_ARGS+=--enable-cheat-codes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|; \
		s|-lpthread|${PTHREAD_LIBS}|; \
		/^LIBS=/ s|-lggi|& ${PTHREAD_LIBS}|' ${WRKSRC}/configure

post-install:
	${CHGRP} games ${PREFIX}/bin/urban
	${CHMOD} g+s ${PREFIX}/bin/urban
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
