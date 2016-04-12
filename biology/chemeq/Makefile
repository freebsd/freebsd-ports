# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
# $FreeBSD$

PORTNAME=	chemeq
PORTVERSION=	1.50
PORTREVISION=	2
CATEGORIES=	biology textproc
MASTER_SITES=	http://download.gna.org/chemeq/chemeq-1.5/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}_1.5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Outputs LaTeX code for chemical reaction

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-1.5

USES=		bison

PLIST_FILES=	bin/chemeq man/man1/chemeq.1.gz
PORTDOCS=	README
PORTEXAMPLES=	chemreport chemreport.pl chemtest chemtest.pl test.stuff

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chemeq ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/chemeq.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/tests/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
