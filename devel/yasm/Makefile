PORTNAME=	yasm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0-90
DISTVERSIONSUFFIX=	-ga2f8bdf0
CATEGORIES=	devel lang
#MASTER_SITES=	https://www.tortall.net/projects/yasm/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Complete rewrite of the NASM assembler
WWW=		https://yasm.tortall.net/

LICENSE=	BSD3CLAUSE

USES=		cmake:testing localbase:ldflags python:build

USE_GITHUB=	yes

CMAKE_OFF=	YASM_BUILD_TESTS
CMAKE_TESTING_ON=	YASM_BUILD_TESTS # inclear how to run tests, see https://github.com/yasm/yasm/issues/212

OPTIONS_DEFINE=	NLS

NLS_CMAKE_BOOL=	ENABLE_NLS

NLS_USES=	gettext-runtime
NLS_LDFLAGS=	-lintl

post-install:
	# install manpages
	${INSTALL_MAN} ${WRKSRC}/yasm.1 ${STAGEDIR}${PREFIX}/share/man/man1
.for m in yasm_arch yasm_dbgfmts yasm_objfmts yasm_parsers
	${INSTALL_MAN} ${WRKSRC}/${m}.7 ${STAGEDIR}${PREFIX}/share/man/man7
.endfor

.include <bsd.port.mk>
