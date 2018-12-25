# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stxxl
PORTVERSION=	1.4.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Standard Template Library for Extra Large Data Sets

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake
CMAKE_ARGS=	-DINSTALL_PKGCONFIG_DIR:STRING="libdata/pkgconfig" \
		-DUSE_GNU_PARALLEL:BOOL=OFF # may be enabled for future versions of clang with openmp support

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS CHANGELOG README TODO" \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
