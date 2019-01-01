# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iroffer
PORTVERSION=	1.4.3
CATEGORIES=	irc
MASTER_SITES=	http://iroffer.org/archive/v1.4/
DISTNAME=	iroffer1.4.b03

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	IRC "bot" that makes sharing files via DCC extremely easy

LICENSE=	GPLv2

EXPIRATION_DATE=	2019-02-01
DEPRECATED=		Abandoned upstream

CONFLICTS=	iroffer-lamm-1.* iroffer-dinoex-3.*

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
