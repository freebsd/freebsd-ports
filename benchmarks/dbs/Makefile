# Created by: Joseph Koshy <jkoshy@FreeBSD.org>

PORTNAME=	dbs
PORTVERSION=	1.1.5
PORTREVISION=	7
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.kusa.ac.jp/~yukio-m/dbs/software1.1.5/ \
		LOCAL/jkoshy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed network benchmarking system

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	gnuplot:math/gnuplot

BROKEN_FreeBSD_12=	tcp_debug.h: field has incomplete type 'struct tcpcb'
BROKEN_FreeBSD_13=	tcp_debug.h: field has incomplete type 'struct tcpcb'
BROKEN_FreeBSD_14=	tcp_debug.h: field has incomplete type 'struct tcpcb'

BUILD_WRKSRC=	${WRKSRC}/obj/${OPSYS}
INSTALL_WRKSRC=	${WRKSRC}/obj/${OPSYS}

USES=		perl5
USE_PERL5=	run
MAKEFILE=	makefile

PLIST_FILES=	bin/dbs_view bin/dbsc bin/dbsd
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-build:
	cd ${WRKSRC}/src && ${MAKE_CMD} dir

do-install:
.for bin in dbsc dbsd
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor
.for bin in dbs_view
	${INSTALL_SCRIPT} ${WRKSRC}/script/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in Copyright dbs.man dbs.man.jis dbs_paper.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in TCP2.cmd TCPvsMPEG.cmd
	${INSTALL_DATA} ${WRKSRC}/sample/${ex} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
