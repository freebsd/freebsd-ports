# New ports collection makefile for:	3dpong
# Date created:				10 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	3dpong
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/3dpong/

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	makefile
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e 's.	chmod .	${CHMOD} .g' \
		${WRKSRC}/makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/3dpong ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/3dpong
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${PREFIX}/share/3dpong

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/3dpong
	@ ${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/3dpong
.endif

.include <bsd.port.mk>
