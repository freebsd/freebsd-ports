# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	embb
PORTVERSION=	0.2.1
CATEGORIES=	devel

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Embedded Multicore Building Blocks

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	riggs-
GH_COMMIT=	d40a5c3
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake:outsource compiler:c11

CMAKE_ARGS=	-DINSTALL_PREFIX=${PREFIX} \
		-DBUILD_TESTS=OFF

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_CMAKE_OFF=	-DINSTALL_DOCS=OFF

OPTIONS_SUB=	yes

post-patch:
	${RM} ${WRKSRC}/doc/examples/CMakeLists.txt
	${MV} ${WRKSRC}/doc/examples ${WRKSRC}

post-install:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}/${EXAMPLESDIR}

.include <bsd.port.mk>
