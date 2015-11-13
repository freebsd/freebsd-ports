# $FreeBSD$

PORTNAME=	iroffer
PORTVERSION=	1.4.3.2
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}-lamm/${PORTNAME}1.4-lamm/${PORTNAME}1.4.b03-lamm.b02
PKGNAMESUFFIX=	-lamm${PKGNAMESUFFIX2}
DISTNAME=	iroffer1.4.b03-lamm.b02

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	IRC "bot" that makes sharing files via DCC extremely easy

LICENSE=	GPLv2

CONFLICTS=	iroffer-1.* iroffer-dinoex-3.*

USES=		tar:tgz
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|cctype="gcc"|cctype="${CC}"|' \
		${WRKSRC}/Configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/convertxdccfile ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dynip.sh ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/iroffer.cron ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample.config ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
