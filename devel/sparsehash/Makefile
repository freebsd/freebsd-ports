# Created by: Vasil Dimov <vd@datamax.bg>
# $FreeBSD$

PORTNAME=	sparsehash
PORTVERSION=	2.0.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Extremely memory-efficient hash_map implementation

LICENSE=	BSD3CLAUSE

USES=		pathfix
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch-DOCS-on:
	${REINPLACE_CMD} -e \
		's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in

post-patch-DOCS-off:
	${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in

regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.mk>
