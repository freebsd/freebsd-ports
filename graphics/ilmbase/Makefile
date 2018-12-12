# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	ilmbase
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	https://github.com/openexr/openexr/releases/download/v${PORTVERSION}/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD3CLAUSE

# there are some systems that have a static /bin/bash, so
# in order to make BUILD_DEPENDS effective, use the same absolute
# path we will pass down through CONFIGURE_SHELL below.
BUILD_DEPENDS=	${BASH_CMD}:shells/bash

USES=		compiler:c++14-lang pkgconfig libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
# The configure script uses bash arrays
CONFIGURE_SHELL=${BASH_CMD}
CONFIGURE_ARGS=	--disable-static
TEST_TARGET=	check

PORTDOCS=	AUTHORS ChangeLog README.md
OPTIONS_DEFINE=		DOCS LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependent large stack optimizations
LARGE_STACK_CONFIGURE_ENABLE=	large-stack

BASH_CMD=	${LOCALBASE}/bin/bash

OPTIONS_SUB=	yes

MAJORVER=	2_3
VER=		24

PLIST_SUB=	MAJORVER=${MAJORVER}
PLIST_SUB+=	VER=${VER}

HALF_BIN=	eLut toFloat

regression-test regression check::	test

post-configure:
	${REINPLACE_CMD} -e 's/#define HAVE_UCONTEXT_H 1/#undef HAVE_UCONTEXT_H/' ${WRKSRC}/config/IlmBaseConfig.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libHalf.so.${VER}
	${RM} ${STAGEDIR}${PREFIX}/lib/*.la
.for l in libIex libIexMath libImath libIlmThread
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}-${MAJORVER}.so.${VER}
	@#${LN} -s ${l}-${MAJORVER}.so.${VER} ${STAGEDIR}${PREFIX}/lib/${l}.so || :
	${LN} -s ${l}.so ${STAGEDIR}${PREFIX}/lib/${l}-${MAJORVER}.so
.endfor

.for e in ${HALF_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/Half/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
