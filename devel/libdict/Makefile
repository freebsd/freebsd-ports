# New ports collection makefile for:	libdict
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	libdict
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://home.earthlink.net/~smela1/libdict/  \
		http://home.earthlink.net/~smela1/	    \
		http://home.earthlink.net/~smela1/libdict/algorithms/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}.html \
		treap_insert.dvi treap_insert.pdf	    \
		avl_insert.dvi avl_insert.pdf		    \
		empty.dvi empty.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Library providing access to ``dictionary'' data structures

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

post-extract:
	@${CP} ${DISTDIR}/${PORTNAME}.html ${WRKSRC}/
.	for ___f in avl_insert.dvi avl_insert.pdf empty.dvi empty.pdf treap_insert.dvi treap_insert.pdf
	@${CP} ${DISTDIR}/${___f} ${WRKSRC}/
.	endfor

pre-install:
	-@${MKDIR} ${PREFIX}/include/
	-@${MKDIR} ${PREFIX}/lib/
	-@${MKDIR} ${DOCSDIR}

post-install:
.	for ___f in avl_insert.dvi avl_insert.pdf empty.dvi empty.pdf treap_insert.dvi treap_insert.pdf ${PORTNAME}.html
	@${CP} ${WRKSRC}/${___f} ${DOCSDIR}
.	endfor

.include <bsd.port.mk>
