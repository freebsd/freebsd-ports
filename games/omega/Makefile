# New ports collection makefile for:	omega
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	omega
PORTVERSION=	0.90.4
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	# empty
MAN6=		omega.6

PORTDOCS=	buglist.txt docs/compile.all docs/omega.txt docs/readme.1st \
		docs/readme3 docs/readme4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omega ${PREFIX}/bin
	@${CHOWN} root:games ${PREFIX}/bin/omega
	@${CHMOD} 2711 ${PREFIX}/bin/omega
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/omega
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/omega
	@${RM} ${PREFIX}/share/omega/license.old
	@${CHMOD} 0460 ${PREFIX}/share/omega/omega.hi
	@${CHMOD} 0460 ${PREFIX}/share/omega/omega.log
	${CP} ${PREFIX}/share/omega/omega.hi ${PREFIX}/share/omega/omegahi.bak
	@${CHMOD} 0460 ${PREFIX}/share/omega/omegahi.bak
	@${CHOWN} -R root:games ${PREFIX}/share/omega
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/omega
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/omega
.endfor
.endif

.include <bsd.port.mk>
