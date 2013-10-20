# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	qstat
PORTVERSION=	2.11
CATEGORIES=	games net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Command-line program to query game servers on the net

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	torque-[0-9]*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/qstat.cfg ${WRKSRC}/qstat.cfg.default

post-patch:
	@${REINPLACE_CMD} -e 's|qstat\.cfg|&.default|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|OpenBSD|${OPSYS}|' ${WRKSRC}/qstat.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/info ${STAGEDIR}${DOCSDIR}/template
	${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/template/*.html ${WRKSRC}/template/*.txt \
		${STAGEDIR}${DOCSDIR}/template
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${STAGEDIR}${DOCSDIR}/info

.include <bsd.port.mk>
