# Created by: perlguy@perlguy.com
# $FreeBSD$

PORTNAME=	infobot
PORTVERSION=	0.45.3
CATEGORIES=	irc
MASTER_SITES=	http://www.infobot.org/src/ \
		http://www.infobot.org/src/prior/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bot written in Perl with a rabid AI

USES=		perl5
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	${CP} -r ${WRKSRC}/src ${WRKSRC}/extras ${WRKSRC}/files \
		${WRKSRC}/scripts ${DATADIR}/
	${RM} ${DATADIR}/src/*.orig
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/README ${WRKSRC}/REVISIONS ${DOCSDIR}
.endif
	${MKDIR} ${PREFIX}/etc/infobot
	${INSTALL_DATA} ${WRKSRC}/conf/* ${PREFIX}/etc/infobot
	${SED} -e 's,$$param{\(.\)basedir\(.\)} = .*,$$param{\1basedir\2} = "${DATADIR}";,' \
	-e 's,$$param{\(.\)confdir\(.\)} = .*,$$param{\1confdir\2} = "${PREFIX}/etc/infobot";,' \
	${WRKSRC}/infobot  > ${WRKDIR}/infobot
	${INSTALL_SCRIPT} ${WRKDIR}/infobot ${PREFIX}/bin

.include <bsd.port.mk>
