# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	njplot
PORTVERSION=	2.4
CATEGORIES=	biology
MASTER_SITES=	http://awarnach.mathstat.dal.ca/distfiles/ \
		ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/njplot/ \
		ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/njplot/archive/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Phylogenetic tree drawing program

LICENSE=	NONE

BUILD_DEPENDS=	blastall:biology/ncbi-toolkit

MAKEFILE=	makefile

USES=		motif
USE_XORG=	x11 xmu xp xt

BINARIES=	newicktops newicktotxt njplot unrooted
PLIST_FILES=	${BINARIES:S|^|bin/|} man/man1/njplot.1.gz \
		man/man1/unrooted.1.gz
PORTDATA=	njplot.help
PORTDOCS=	njplot.html njplot.gif

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BINARIES:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/njplot.help ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
