PORTNAME=	libboard
DISTVERSION=	0.9.6
CATEGORIES=	graphics

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Vector graphics C++ library
WWW=		https://github.com/c-koi/libboard

LICENSE=	LGPL3

USES=		cmake compiler:c++11-lang localbase magick

USE_GITHUB=	yes
GH_ACCOUNT=	c-koi
GH_TAGNAME=	5b38274

USE_CXXSTD=	c++11
CMAKE_ARGS=	-DMYPROJ_RAN_ONCE:BOOL=YES	\
		-DEXECUTABLE_OUTPUT_PATH:PATH="${STAGEDIR}${EXAMPLESDIR}"
USE_LDCONFIG=	yes

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN EXAMPLES DOCS
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libboard.so ${STAGEDIR}${PREFIX}/lib/libboard.so.0
	${LN} -sf libboard.so.0 ${STAGEDIR}${PREFIX}/lib/libboard.so

do-test:
	(cd ${STAGEDIR}${EXAMPLESDIR} && ./arithmetic bec)
.for ex in 1 2 3
	(cd ${STAGEDIR}${EXAMPLESDIR} && ./example${ex})
.endfor

.include <bsd.port.mk>
