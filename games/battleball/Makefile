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
		http://fundy.linux.tucows.com/files/x11/entertain/
DISTNAME=	${PORTNAME}.${PORTVERSION:S/.//}.src

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_MESA=	yes
WRKSRC=		${WRKDIR}/battleball-2.1-src

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/battleball ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/battleball
.for file in CHANGELOG README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/battleball
.endfor
.endif

.include <bsd.port.mk>
