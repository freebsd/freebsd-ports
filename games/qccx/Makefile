# New ports collection makefile for:	QCCX
# Date created:				18 Jan 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qccx
PORTVERSION=	1.0.0
CATEGORIES=	games devel
MASTER_SITES=	http://www.quakewiki.net/archives/qccx/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A very fast optimizing QuakeC compiler

LICENSE=	GPLv2

USE_ZIP=	yes
USE_DOS2UNIX=	pr_comp.cpp qcc.cpp ${PORTDOCS}

NO_WRKSUBDIR=	yes
MAKEFILE=	${FILESDIR}/Makefile
PORTDOCS=	manual.txt readme.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qc ${WRKSRC}/progs.src ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake-source/Makefile.include"
.include <bsd.port.mk>
