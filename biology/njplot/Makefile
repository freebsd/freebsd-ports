# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	njplot
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/njplot/archive/

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Phylogenetic tree drawing program capable of interactive manipulation

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

OPTIONS_DEFINE=		DOCS X11
OPTIONS_DEFAULT=	DOCS X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
BUILD_DEPENDS=	${LOCALBASE}/lib/ncbi/libvibrant.a:${PORTSDIR}/biology/ncbi-toolkit
USE_XORG=	x11 xt xmu xp
USES=		motif
.endif

MAKEFILE=	makefile

BINARIES=	newicktops newicktotxt
.if ${PORT_OPTIONS:MX11}
BINARIES+=	njplot unrooted
.endif
.for file in ${BINARIES}
PLIST_FILES+=	bin/${file}
.endfor

PORTDOCS=	njplot.help njplot.html njplot.gif

MAN_1=		njplot.1 unrooted.1
PLIST_FILES+=	man/man1/njplot.1.gz \
		man/man1/unrooted.1.gz

.if !${PORT_OPTIONS:MX11}
post-patch:
	${REINPLACE_CMD} -e 's|njplot.*unrooted||' ${WRKSRC}/makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${BINARIES:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${MAN_1:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
