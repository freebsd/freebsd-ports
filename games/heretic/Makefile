# New ports collection makefile for:	glheretic
# Version required:	1.0
# Date created:		04 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	glheretic-1.0
PKGNAME=	heretic-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.raven-games.com/linuxheretic/heretic/src/ \
		http://www.raven-games.com/linuxheretic/wad/
.if !defined(NO_WAD)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} heretic_share.wad.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	will@FreeBSD.org

FETCH_BEFORE_ARGS+=	-b
USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	WANT_OGL="no" WANT_OGL_FULLSCREEN="no" WANT_NICE_OGL="no"
.if !defined(NO_WAD)
PLIST=		${PKGDIR}/PLIST.nowad
.endif
ALL_TARGET=	x11
BINARY=		xheretic
.if defined(WANT_FASTX11)
BINARY=		xaheretic
ALL_TARGET=	fastx11
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/heretic
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/heretic
.if !defined(NO_WAD)
	@${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/heretic_share.wad.gz \
		> ${PREFIX}/share/heretic/heretic_share.wad
.endif

.include <bsd.port.mk>
