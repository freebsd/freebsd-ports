# New ports collection makefile for:	makeself
# Date created:		22 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	makeself
PORTVERSION=	2.1.2
CATEGORIES=	archivers
MASTER_SITES=	http://www.megastep.org/makeself/
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A neat script to make self-extracting archives

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	--nox11 --target ${WRKSRC}

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makeself.sh ${PREFIX}/bin/makeself
	${INSTALL_SCRIPT} ${WRKSRC}/makeself-header.sh ${PREFIX}/bin/makeself-header.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
