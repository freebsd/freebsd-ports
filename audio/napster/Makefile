# New ports collection makefile for:    napster
# Version required:     0.7BETA
# Date created:         Thu Nov 18 01:07:00 PST 1999
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	nap-bsd-0.7BETA
PKGNAME=	napster-0.7b
CATEGORIES=	audio net
MASTER_SITES=	http://www.gis.net/~nite/

MAINTAINER=	dburr@FreeBSD.org

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/nap
NO_BUILD=	yes

do-install:
	${INSTALL} -c -o root -g wheel -m 555 ${WRKSRC}/nap ${PREFIX}/bin/nap
	${MKDIR} ${PREFIX}/share/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf ${PREFIX}/share/nap
.if (!defined(NOPORTDOCS))
	@${ECHO_MSG} "===>  Installing README in ${PREFIX}/share/doc/nap"
	${MKDIR} ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
.endif

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
