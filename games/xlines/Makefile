# New ports collection makefile for:	xlines
# Date created:				11 February 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xlines
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.trolltech.com/contrib/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_QT_VER=	1
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

pre-patch:
	@find ${WRKSRC} -type f | xargs ${PERL} -pi -e "s|\r\n|\n|g"

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlines ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xlines
	${INSTALL_DATA} ${WRKSRC}/trolltech.gif ${PREFIX}/share/xlines
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xlines
	${INSTALL_DATA} ${WRKSRC}/readme.lines ${PREFIX}/share/doc/xlines
	${INSTALL_DATA} ${WRKSRC}/readme.qt ${PREFIX}/share/doc/xlines
.endif

.include <bsd.port.mk>
