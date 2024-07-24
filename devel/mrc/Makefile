PORTNAME=	mrc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.13
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Maartens Resource Compiler
WWW=		https://github.com/mhekkel/mrc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libmcfp>0:devel/libmcfp
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	mhekkel

CMAKE_OFF=	BUILD_TESTING

PLIST_FILES=	bin/mrc \
		share/man/man1/mrc.1.gz \
		share/mrc/cmake/mrc-config.cmake

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install: # workaround for https://github.com/mhekkel/mrc/issues/9
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/mrc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
