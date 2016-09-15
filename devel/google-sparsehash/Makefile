# Created by: Vasil Dimov <vd@datamax.bg>
# $FreeBSD$

PORTNAME=	google-sparsehash
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/vd/${PORTNAME}
PROJECTHOST=	sparsehash
DISTNAME=	sparsehash-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Extremely memory-efficient hash_map implementation

BROKEN=		Unfetchable (google code has gone away)

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e \
		's|^pkgconfigdir = .*|pkgconfigdir = ${LOCALBASE}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

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
