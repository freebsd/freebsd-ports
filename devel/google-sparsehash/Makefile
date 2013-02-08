# New ports collection makefile for:	google-sparsehash
# Date created:				23 June 2005
# Whom:					Vasil Dimov <vd@datamax.bg>
#
# $FreeBSD$
#

PORTNAME=	google-sparsehash
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/${PORTNAME}
PROJECTHOST=	sparsehash
DISTNAME=	sparsehash-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	An extremely memory-efficient hash_map implementation

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e \
		's|^pkgconfigdir = .*|pkgconfigdir = ${LOCALBASE}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
