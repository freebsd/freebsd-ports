PORTNAME=	leatherman
PORTVERSION=	1.12.9
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Leatherman C++ Tool library
WWW=		https://github.com/puppetlabs/leatherman

LICENSE=	APACHE20

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++11-lang cmake gettext ruby
USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
USE_LDCONFIG=	yes

CMAKE_ON=	LEATHERMAN_SHARED
CMAKE_OFF=	ENABLE_CXX_WERROR

TEST_TARGET=	test

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

post-configure:
	# This file is vendored in vendor/Catch-1.10.0.zip and extracted at configure step
	${SED} -i '' -e '1s|\(.*\)|#include <sys/signal.h>\n\1|' ${CONFIGURE_WRKSRC}/src/Catch-1.10.0/single_include/catch.hpp
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
	${REINPLACE_CMD} -e 's|ptrdiff_t|size_t|' ${CONFIGURE_WRKSRC}/src/Catch-1.10.0/single_include/catch.hpp
.endif

.include <bsd.port.post.mk>
