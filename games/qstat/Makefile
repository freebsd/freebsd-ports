# New ports collection makefile for:   qstat
# Date created:        28 May 1998
# Whom:                Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	qstat
PORTVERSION=	2.8
CATEGORIES=	games net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A command line program to query game servers on the net

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-extract:
	@${MV} ${WRKSRC}/qstat.cfg ${WRKSRC}/qstat.cfg.default

post-patch:
	@${REINPLACE_CMD} -e 's|\(qstat\.cfg\)|\1\.default|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installing documents and templates in: \
		${DOCSDIR}"
	@${ECHO_MSG} ""
	@${MKDIR} ${DOCSDIR}/info ${DOCSDIR}/template
	@${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/template/*.html ${WRKSRC}/template/*.txt \
		${DOCSDIR}/template
	@${INSTALL_DATA} ${WRKSRC}/info/*.txt ${DOCSDIR}/info
.endif
	@[ -f ${PREFIX}/etc/qstat.cfg ] || \
		${CP} ${PREFIX}/etc/qstat.cfg.default ${PREFIX}/etc/qstat.cfg

.include <bsd.port.mk>
