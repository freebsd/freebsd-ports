# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbs
PORTVERSION=	1.1.5
PORTREVISION=	6
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.kusa.ac.jp/~yukio-m/dbs/software1.1.5/ \
		LOCAL/jkoshy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed network benchmarking system

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

BUILD_WRKSRC=	${WRKSRC}/obj/${OPSYS}
INSTALL_WRKSRC=	${WRKSRC}/obj/${OPSYS}

USES=		perl5
USE_PERL5=	run
MAKEFILE=	makefile

PLIST_FILES=	bin/dbs_view bin/dbsc bin/dbsd
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}|' ${WRKSRC}/script/dbs_view

pre-build:
	cd ${WRKSRC}/src; ${MAKE} dir

do-install:
.for bin in dbsc dbsd
	cd ${INSTALL_WRKSRC}; ${INSTALL_PROGRAM} ${bin} ${PREFIX}/bin
.endfor
.for bin in dbs_view
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} ${bin} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in Copyright dbs.man dbs.man.jis dbs_paper.ps
	cd ${WRKSRC}/doc; ${INSTALL_DATA} ${doc} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for ex in TCP2.cmd TCPvsMPEG.cmd
	cd ${WRKSRC}/sample; ${INSTALL_DATA} ${ex} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
