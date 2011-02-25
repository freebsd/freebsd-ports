# New ports collection makefile for:	funnyboat
# Date created:		18 Mar 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	funnyboat
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A side scrolling shooter game starring a steamboat on the sea

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_PYTHON=	2.5+
NO_BUILD=	yes

SUB_FILES=	funnyboat_
SUB_LIST=	PROGRAM_DIR="${PREFIX}/lib/${PORTNAME}"

PORTDOCS=	README.txt

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/data
	${INSTALL_DATA} ${WRKSRC}/*.py ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/data/* ${PREFIX}/lib/${PORTNAME}/data
	${INSTALL_SCRIPT} ${WRKDIR}/funnyboat_ ${PREFIX}/bin/funnyboat

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
