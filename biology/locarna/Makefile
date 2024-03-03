PORTNAME=	locarna
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	https://github.com/s-will/LocARNA/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LocARNA provides several tools for the structural analysis of RNA
WWW=		https://github.com/s-will/LocARNA

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libRNA.a:biology/viennarna
LIB_DEPENDS=	libgmp.so:math/gmp \
		libgsl.so:math/gsl \
		libmpfr.so:math/mpfr
TEST_DEPENDS=	bash:shells/bash \
		catch>0:devel/catch

USES=		autoreconf gmake libtool perl5 pkgconfig shebangfix
USE_LDCONFIG=	yes
USE_CXXSTD=	c++14 # workaround for https://github.com/s-will/LocARNA/issues/82 (LocARNA uses the removed STL method)

CXXFLAGS+=	-I${LOCALBASE}/include/catch2 # use external catch

SHEBANG_FILES=	src/Utils/locarna_mcc \
		src/Tests/test_programs

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # one test fails, see https://github.com/s-will/LocARNA/issues/81

post-extract: # unbundle catch, see https://github.com/s-will/LocARNA/issues/80
	@${RM} ${WRKSRC}/src/Tests/catch.hpp

.include <bsd.port.mk>
