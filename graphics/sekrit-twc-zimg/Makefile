# $FreeBSD$

PORTNAME=	zimg
PORTVERSION=	2.1
DISTVERSIONPREFIX=	release-
CATEGORIES=	graphics
PKGNAMEPREFIX=	${GH_ACCOUNT}-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scaling, colorspace conversion, and dithering library

LICENSE=	WTFPL2
LICENSE_NAME=	Do What The Fuck You Want To Public License version 2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

USE_GITHUB=	yes
GH_ACCOUNT=	sekrit-twc

CONFLICTS_INSTALL=	zimg-[0-9]* # include/zimg.h

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix
EXTRACT_AFTER_ARGS=	--exclude test/extra
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --enable-testapp
CPPFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	TEST

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD # runtime detection

SIMD_CONFIGURE_ENABLE=	x86simd

TEST_BUILD_DEPENDS=	googletest>=1.6.0:devel/googletest
TEST_USES=		localbase
TEST_CONFIGURE_ENABLE=	unit-test
TEST_TEST_TARGET=	check VERBOSE=1

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/-O2 //' \
		-e '/zimg-test/ { s/+=/=/; s/^noinst_/bin_/; } ' \
		${WRKSRC}/Makefile.am

pre-install-TEST-on: do-test

.include <bsd.port.mk>
