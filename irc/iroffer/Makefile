# New ports collection makefile for:	iroffer
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	iroffer
PORTVERSION=	1.4.2
CATEGORIES=	irc
MASTER_SITES=	http://iroffer.org/archive/v1.4/
DISTNAME=	iroffer1.4.b02
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.ORG
COMMENT=	An IRC "bot" that makes sharing files via DCC extremely easy

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/convertxdccfile ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/dynip.sh ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/iroffer.cron ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample.config ${EXAMPLESDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
