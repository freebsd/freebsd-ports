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

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e \
		's|^pkgconfigdir = .*|pkgconfigdir = ${LOCALBASE}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e \
		's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.else
	${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.mk>
