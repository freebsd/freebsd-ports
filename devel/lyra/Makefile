PORTNAME=	lyra
DISTVERSION=	1.5.1-27
DISTVERSIONSUFFIX=	-gc6fdb1f
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line parser for C++11

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	b2:devel/boost_build

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	bfgroup
GH_PROJECT=	Lyra

NO_ARCH=	yes

do-test: install # one test fails: https://github.com/bfgroup/Lyra/issues/57
	@cd ${WRKSRC}/tests && b2 toolset=clang

.include <bsd.port.mk>
