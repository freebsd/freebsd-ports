# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	njplot
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/njplot/archive/

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Phylogenetic tree drawing program capable of interactive manipulation

.ifndef (WITHOUT_X11)
BUILD_DEPENDS=	${LOCALBASE}/lib/ncbi/libvibrant.a:${PORTSDIR}/biology/ncbi-toolkit
USE_XORG=	x11 xt xmu xp
USES=		motif
.endif

MAKEFILE=	makefile

BINARIES=	newicktops newicktotxt
.ifndef (WITHOUT_X11)
BINARIES+=	njplot unrooted
.endif
.for file in ${BINARIES}
PLIST_FILES+=	bin/${file}
.endfor

PORTDOCS=	njplot.help njplot.html njplot.gif

MAN1=		njplot.1 unrooted.1

.ifdef (WITHOUT_X11)
post-patch:
	${REINPLACE_CMD} -e 's|njplot.*unrooted||' ${WRKSRC}/makefile
.endif

do-install:
.for file in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
