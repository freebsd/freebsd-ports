# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	libboard
DISTVERSION=	0.9.4
PORTREVISION=	7
CATEGORIES=	graphics

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Vector graphics C++ library

LICENSE=	LGPL3

LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6

USES=		cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	c-koi
GH_TAGNAME=	5b38274

CXXFLAGS+=	-D_GLIBCXX_USE_C99 -fPIC # XXX ports/193528
USE_CXXSTD=	c++11
CMAKE_ARGS=	-DMYPROJ_RAN_ONCE:BOOL=YES	\
		-DEXECUTABLE_OUTPUT_PATH:PATH="${STAGEDIR}${EXAMPLESDIR}"
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN EXAMPLES DOCS
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libboard.so ${STAGEDIR}${PREFIX}/lib/libboard.so.0
	${LN} -sf libboard.so.0 ${STAGEDIR}${PREFIX}/lib/libboard.so

do-test:
	(cd ${WRKDIR} && ${WRKSRC}/bin/arithmetic bec)
.for ex in 1 2 3
	(cd ${WRKDIR} && ${WRKSRC}/bin/example${ex})
.endfor
	${LS} -l ${WRKDIR}/arithm* ${WRKDIR}/example*

.include <bsd.port.mk>
