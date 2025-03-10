PORTNAME=	libboard
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector graphics C++ library
WWW=		https://github.com/c-koi/libboard

LICENSE=	LGPL3

USES=		cmake compiler:c++11-lang magick
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	c-koi

PORTDOCS=	*

CMAKE_OFF=	CMAKE_CXX_EXTENSIONS
CMAKE_ON=	MYPROJ_RAN_ONCE

OPTIONS_DEFINE=	DOXYGEN EXAMPLES DOCS
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libboard.so ${STAGEDIR}${PREFIX}/lib/libboard.so.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libboard.so.0 ${STAGEDIR}${PREFIX}/lib/libboard.so
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/examples-bin/* ${STAGEDIR}${EXAMPLESDIR}

do-test:
	(cd ${TEST_WRKSRC}/examples-bin && ./arithmetic bec)
.for ex in 1 2 3
	(cd ${TEST_WRKSRC}/examples-bin && ./example${ex})
.endfor

.include <bsd.port.mk>
