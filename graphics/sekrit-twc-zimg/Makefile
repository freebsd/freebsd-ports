# $FreeBSD$

PORTNAME=	zimg
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	${GH_ACCOUNT}-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scaling, colorspace conversion, and dithering library

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	sekrit-twc

CONFLICTS_INSTALL=	zimg-[0-9]* # include/zimg.h

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix
EXTRACT_AFTER_ARGS=	--exclude test/extra
GNU_CONFIGURE=	yes
CPPFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
CPPFLAGS+=	${CPPFLAGS_${CHOSEN_COMPILER_TYPE}_${COMPILER_VERSION}}
CPPFLAGS_clang_34=	-include x86intrin.h # revert 575bd93
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES TEST

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD # runtime detection

EXAMPLES_CONFIGURE_ENABLE=	example
EXAMPLES_MAKE_ARGS=	exampledir="${EXAMPLESDIR}"
EXAMPLES_MAKE_ARGS_OFF=	dist_example_DATA= dist_examplemisc_DATA=

SIMD_CONFIGURE_ENABLE=	x86simd

TEST_BUILD_DEPENDS=	googletest>=1.6.0:devel/googletest
TEST_USES=		localbase
TEST_CONFIGURE_ENABLE=	unit-test
TEST_TEST_TARGET=	check VERBOSE=1

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/-O2 //' \
		-e '/dist_doc_DATA/d' \
		${WRKSRC}/Makefile.am

pre-install-TEST-on: do-test

.include <bsd.port.mk>
