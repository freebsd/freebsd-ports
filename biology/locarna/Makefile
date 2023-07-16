PORTNAME=	locarna
DISTVERSION=	2.0.0
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

USES=		autoreconf gmake libtool perl5 pkgconfig shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/Utils/locarna_mcc

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # tests fail to compile, see https://github.com/s-will/LocARNA/issues/80

.include <bsd.port.mk>
