# New ports collection makefile for:	battleball
# Date created:				18 December 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	battleball
PORTVERSION=	2.1
CATEGORIES=	games
MASTER_SITES=	http://tzo.linux.tucows.com/files/x11/entertain/ \
		http://fundy.linux.tucows.com/files/x11/entertain/ \
		http://207.211.212.35/pah/

DISTNAME=	${PORTNAME}.${PORTVERSION:S/.//}.src

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	3D single/multiplayer military soccer game for X Window System

USE_X_PREFIX=	yes
USE_MESA=	yes
WRKSRC=		${WRKDIR}/battleball-2.1-src
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
