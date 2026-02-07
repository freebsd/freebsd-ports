PORTNAME=	tinyopt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-8
DISTVERSIONSUFFIX=	-gef7d72c
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for argument parsing
WWW=		https://github.com/halfflat/tinyopt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		gmake localbase

USE_GITHUB=	yes
GH_ACCOUNT=	halfflat

PLIST_FILES=	bin/${PORTNAME}

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/tinyopt/tinyopt.h

do-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include/

do-test: # tests fail to compile because they look for the file gtest-all.cc, see https://github.com/halfflat/tinyopt/issues/21
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all test

.include <bsd.port.mk>
