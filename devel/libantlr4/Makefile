PORTNAME=	antlr4
DISTVERSION=	4.13.0
DISTVERSIONPREFIX=	cpp-runtime-
DISTVERSIONSUFFIX=	-source
CATEGORIES=	devel
MASTER_SITES=	http://www.antlr.org/download/
PKGNAMEPREFIX=		lib

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition (C runtime)
WWW=		https://www.antlr.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp

USES=		cmake:testing compiler:c11 localbase:ldflags zip

NO_WRKSUBDIR=	yes

CMAKE_OFF=	ANTLR_BUILD_CPP_TESTS
CMAKE_TESTING_ON=	ANTLR_BUILD_CPP_TESTS # tests fail to link, see https://github.com/antlr/antlr4/issues/4074

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
LIBVERSION=	${PORTVERSION}
PLIST_SUB+=	LIBVERSION=${PORTVERSION}

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/antlr4-runtime/.idea

.include <bsd.port.mk>
