# Created by: Alex Semenyaka <alex@rinet.ru>
# $FreeBSD$

PORTNAME=	libdict
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source treap_insert.pdf:doc \
		avl_insert.pdf:doc empty.pdf:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library providing access to ``dictionary'' data structures

USES=		gmake
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

post-extract:
.	for ___f in avl_insert.pdf empty.pdf treap_insert.pdf
	@${CP} ${DISTDIR}/${___f} ${WRKSRC}/
.	endfor


post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for ___f in avl_insert.pdf empty.pdf treap_insert.pdf
	@${CP} ${WRKSRC}/${___f} ${STAGEDIR}${DOCSDIR}
.	endfor

.include <bsd.port.mk>
