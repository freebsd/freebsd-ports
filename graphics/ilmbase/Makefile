# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ilmbase
PORTVERSION=	2.5.1
CATEGORIES=	graphics devel

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++14-lang libtool pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	AcademySoftwareFoundation:openexr:v${PORTVERSION}
USE_LDCONFIG=	yes

CMAKE_ARGS+=	--target \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		install

WRKSRC_SUBDIR=	IlmBase

PLIST_SUB=	MAJORVER=${_MAJORVER} \
		VER=${_VER}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS LARGE_STACK
OPTIONS_SUB=	yes

LARGE_STACK_DESC=		Enable sys-dependent large stack optimizations
LARGE_STACK_CMAKE_BOOL=		ILMBASE_ENABLE_LARGE_STACK
LARGE_STACK_CONFIGURE_ENABLE=	large-stack

_MAJORVER=	2_5
_VER=		25

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libHalf-${_MAJORVER}.so
.for l in libHalf libIex libIexMath libImath libIlmThread
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}-${_MAJORVER}.so
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ctest

.include <bsd.port.mk>
