# New ports collection makefile for:	omega
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	omega
PORTVERSION=	0.90.4
CATEGORIES=	games
MASTER_SITES=	http://dolphin.openprojects.net/Omega/Downloads/Prealphas/
DISTNAME=	omega-0.90-pa4

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=
WRKSRC=		${WRKDIR}/omega
MAN6=		omega.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/omega ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${PREFIX}/man/man6
	@ ${CHOWN} root:games ${PREFIX}/bin/omega
	@ ${CHMOD} 2711 ${PREFIX}/bin/omega
	@ ${MKDIR} ${PREFIX}/share/omega
	@ ${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/omega
	@ ${RM} ${PREFIX}/share/omega/license.old
	@ ${CHMOD} 0460 ${PREFIX}/share/omega/omega.hi
	@ ${CHMOD} 0460 ${PREFIX}/share/omega/omega.log
	@ ${CP} ${PREFIX}/share/omega/omega.hi ${PREFIX}/share/omega/omegahi.bak
	@ ${CHMOD} 0460 ${PREFIX}/share/omega/omegahi.bak
	@ ${CHOWN} -R root:games ${PREFIX}/share/omega

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/omega
.for file in buglist.txt docs/compile.all docs/readme.1st docs/omega.txt docs/readme3 docs/readme4
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/omega
.endfor
.endif

.include <bsd.port.mk>
