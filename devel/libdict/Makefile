# New ports collection makefile for:	libdict
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	libdict
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.crazycoder.org/libdict/:source \
		http://www.crazycoder.org/libdict/algorithms/:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source treap_insert.pdf:doc \
		avl_insert.pdf:doc empty.pdf:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Library providing access to ``dictionary'' data structures

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

post-extract:
.	for ___f in avl_insert.pdf empty.pdf treap_insert.pdf
	@${CP} ${DISTDIR}/${___f} ${WRKSRC}/
.	endfor

pre-install:
	-@${MKDIR} ${PREFIX}/include/
	-@${MKDIR} ${PREFIX}/lib/
	-@${MKDIR} ${DOCSDIR}

post-install:
.	for ___f in avl_insert.pdf empty.pdf treap_insert.pdf
	@${CP} ${WRKSRC}/${___f} ${DOCSDIR}
.	endfor

.include <bsd.port.mk>
