PORTNAME=	gumbo
DISTVERSION=	0.13.2
PORTREVISION=	2
CATEGORIES=	devel textproc
MASTER_SITES=	https://codeberg.org/gumbo-parser/gumbo-parser/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy/

MAINTAINER=	fsbruva@yahoo.com
COMMENT=	Pure-C HTML5 parser
WWW=		https://codeberg.org/gumbo-parser/gumbo-parser/

LICENSE=	APACHE20

USES=		meson pkgconfig
USE_LDCONFIG=	yes

PIE_UNSAFE=	yes

WRKSRC=		${WRKDIR}/gumbo-parser

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST

TEST_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtest_main.pc:devel/googletest
TEST_MESON_TRUE=	tests

do-test-TEST-on:
	cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} meson test --print-errorlogs

.include <bsd.port.mk>
