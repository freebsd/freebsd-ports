# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ilmbase
PORTVERSION=	2.4.1
CATEGORIES=	graphics devel

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD3CLAUSE

# there are some systems that have a static /bin/bash, so
# in order to make BUILD_DEPENDS effective, use the same absolute
# path we will pass down through CONFIGURE_SHELL below.
BUILD_DEPENDS=	${BASH_CMD}:shells/bash

USES=		cmake compiler:c++14-lang pkgconfig libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	AcademySoftwareFoundation:openexr:v${PORTVERSION}
WRKSRC_SUBDIR=	IlmBase

PORTDOCS=	README.md
OPTIONS_DEFINE=		DOCS LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependent large stack optimizations
LARGE_STACK_CONFIGURE_ENABLE=	large-stack

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX} --target install

BASH_CMD=	${LOCALBASE}/bin/bash

OPTIONS_SUB=	yes

MAJORVER=	2_4
VER=		24

PLIST_SUB=	MAJORVER=${MAJORVER}
PLIST_SUB+=	VER=${VER}

HALF_BIN=	eLut toFloat

test regression-test regression check::
	cd ${BUILD_WRKSRC} && ctest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libHalf-${MAJORVER}.so
	${RM} ${STAGEDIR}${PREFIX}/lib/*.la
.for l in libHalf libIex libIexMath libImath libIlmThread
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}-${MAJORVER}.so
	${LN} -s ${l}-${MAJORVER}.so.${VER} ${STAGEDIR}${PREFIX}/lib/${l}.so || :
.endfor

.for e in ${HALF_BIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Half/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
