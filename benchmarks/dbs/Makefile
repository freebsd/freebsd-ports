# New ports collection makefile for: dbs
# Date created: 	1 August 1998
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	dbs
PORTVERSION=	1.1.5
PORTREVISION=	5
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.kusa.ac.jp/~yukio-m/dbs/software1.1.5/ \
		LOCAL/jkoshy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A distributed network benchmarking system

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

BUILD_WRKSRC=	${WRKSRC}/obj/${OPSYS}
INSTALL_WRKSRC=	${WRKSRC}/obj/${OPSYS}

USE_PERL5_RUN=	yes
MAKEFILE=	makefile

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/dbs_view bin/dbsc bin/dbsd

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in Copyright dbs.man dbs.man.jis dbs_paper.ps
	cd ${WRKSRC}/doc; ${INSTALL_DATA} ${doc} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for ex in TCP2.cmd TCPvsMPEG.cmd
	cd ${WRKSRC}/sample; ${INSTALL_DATA} ${ex} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
