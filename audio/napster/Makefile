# New ports collection makefile for:    napster
# Date created:         Thu Nov 18 01:07:00 PST 1999
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	napster
PORTVERSION=	1.4.4
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nap
DISTNAME=	nap-${PORTVERSION}

MAINTAINER=	dburr@FreeBSD.org

GNU_CONFIGURE=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/nap
	${INSTALL_DATA} ${WRKSRC}/nap.conf.dist ${PREFIX}/share/nap

.if (!defined(NOPORTDOCS))
	@${ECHO_MSG} "===>  Installing NEWS + README in ${PREFIX}/share/doc/nap"
	${MKDIR} ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
.endif

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} 's:@PREFIX@:${PREFIX}:g'

.include <bsd.port.mk>
