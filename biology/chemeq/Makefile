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

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-1.5

USES=		bison

PLIST_FILES+=	bin/chemeq
MAN1=		chemeq.1
PORTDOCS=	README
PORTEXAMPLES=	chemreport chemreport.pl chemtest chemtest.pl test.stuff

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/chemeq ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/chemeq.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/tests/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
