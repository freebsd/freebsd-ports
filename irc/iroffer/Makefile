# New ports collection makefile for:	iroffer
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	iroffer
PORTVERSION=	1.1.1
CATEGORIES=	irc
MASTER_SITES=	http://iroffer.org/archive/v1.1/
DISTNAME=	iroffer${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dburr@FreeBSD.ORG

do-configure:
		cd ${WRKSRC} && ${SH} ./Configure

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/doc/iroffer
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/iroffer
		${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/iroffer
		${INSTALL_DATA} ${WRKSRC}/iroffer.cron ${PREFIX}/share/doc/iroffer
		${INSTALL_DATA} ${WRKSRC}/sample.config ${PREFIX}/share/doc/iroffer
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
