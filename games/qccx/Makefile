# New ports collection makefile for:	QCCX
# Date created:				18 Jan 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qccx
PORTVERSION=	1.0.0
CATEGORIES=	games devel
MASTER_SITES=	http://www.planetquake.com/qccx/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A very fast optimizing QuakeC compiler

USE_ZIP=	yes
USE_REINPLACE=	yes

MAKEFILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}

post-extract:
	@${FIND} ${WRKDIR} -type f -name "*.[^deo]*" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qc ${WRKSRC}/progs.src ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/[^g]*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
