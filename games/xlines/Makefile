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

PORTCOMMENT=	Remove as many balls from board as you can

USE_QT_VER=	1
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s|`/usr/bin/printf '\r'`||g"

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xlines ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xlines
	${INSTALL_DATA} ${WRKSRC}/trolltech.gif ${PREFIX}/share/xlines
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.lines ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.qt ${DOCSDIR}
.endif

.include <bsd.port.mk>
