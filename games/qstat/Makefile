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

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKSRC}/qstat.cfg ${WRKSRC}/qstat.cfg.default

post-patch:
	@${REINPLACE_CMD} -e 's|\(qstat\.cfg\)|\1\.default|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|OpenBSD|FreeBSD|' ${WRKSRC}/qstat.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/info ${DOCSDIR}/template
	${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/template/*.html ${WRKSRC}/template/*.txt \
		${DOCSDIR}/template
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${DOCSDIR}/info
.endif
	@[ -f ${PREFIX}/etc/qstat.cfg ] || \
		${CP} ${PREFIX}/etc/qstat.cfg.default ${PREFIX}/etc/qstat.cfg

.include <bsd.port.mk>
