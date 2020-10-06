# Created by: Vasil Dimov <vd@datamax.bg>
# $FreeBSD$

PORTNAME=	sparsehash
PORTVERSION=	2.0.4
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Extremely memory-efficient hash_map implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix
USE_GITHUB=	yes
TEST_TARGET=	check

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e \
		's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
