# $FreeBSD$

PORTNAME=	iroffer
PORTVERSION=	1.4.3.2
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}-lamm/${PORTNAME}1.4-lamm/${PORTNAME}1.4.b03-lamm.b02
PKGNAMESUFFIX=	-lamm${PKGNAMESUFFIX2}
DISTNAME=	iroffer1.4.b03-lamm.b02
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An IRC "bot" that makes sharing files via DCC extremely easy

LICENSE=	GPLv2

CONFLICTS=	iroffer-1.* iroffer-dinoex-3.*
NO_STAGE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure

post-patch:
	${REINPLACE_CMD} -e 's|cctype="gcc"|cctype="${CC}"|' \
		${WRKSRC}/Configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/convertxdccfile ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dynip.sh ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/iroffer.cron ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample.config ${EXAMPLESDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
