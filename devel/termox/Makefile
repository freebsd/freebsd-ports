PORTNAME=	termox
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal User Interface framework with NCurses
WWW=		https://github.com/a-n-t-h-o-n-y/CPPurses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		cmake compiler:c++20-lang ncurses
USE_CXXSTD=	c++20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	a-n-t-h-o-n-y
GH_PROJECT=	TermOx
GH_TUPLE=	a-n-t-h-o-n-y:zzz:9d7c047:zzz/ext/zzz \
		a-n-t-h-o-n-y:Escape:f797e81:escape/ext/escape \
		a-n-t-h-o-n-y:signals-light:5b873d0:signals/ext/sl

CMAKE_ARGS=	-DFETCHCONTENT_SOURCE_DIR_ZZZ=${WRKSRC}/ext/zzz \
		-DFETCHCONTENT_SOURCE_DIR_ESCAPE=${WRKSRC}/ext/escape \
		-DFETCHCONTENT_SOURCE_DIR_SIGNALS-LIGHT=${WRKSRC}/ext/sl

CXXFLAGS+=	-fPIC -fexperimental-library

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ox
	cd ${WRKSRC}/include/ox && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ox
	${INSTALL_DATA} ${BUILD_WRKSRC}/libTermOx.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
