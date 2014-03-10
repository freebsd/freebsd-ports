# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qccx
PORTVERSION=	1.0.0
CATEGORIES=	games devel
MASTER_SITES=	http://www.quakewiki.net/archives/qccx/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Very fast optimizing QuakeC compiler

LICENSE=	GPLv2

USES=		dos2unix zip
DOS2UNIX_FILES=	pr_comp.cpp qcc.cpp ${PORTDOCS}
MAKEFILE=	${FILESDIR}/Makefile

NO_WRKSUBDIR=	yes
PORTDOCS=	manual.txt readme.txt

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qc ${WRKSRC}/progs.src ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake-source/Makefile.include"
.include <bsd.port.mk>
