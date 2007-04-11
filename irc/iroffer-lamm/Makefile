# New ports collection makefile for:    iroffer-lamm
# Date created:         10 Apr 2007
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	iroffer
PORTVERSION=	1.4.3.1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	iroffer-lamm
PKGNAMESUFFIX=	-lamm${PKGNAMESUFFIX2}
DISTNAME=	iroffer1.4.b03-lamm.b01
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.ORG
COMMENT=	An IRC "bot" that makes sharing files via DCC extremely easy

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFLICTS=	iroffer-1.*

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
