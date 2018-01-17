# Created by: gahr
# $FreeBSD$

PORTNAME=	catch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	cmake:devel/cmake

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	catchorg
GH_PROJECT=	Catch2

NO_BUILD=	yes
NO_ARCH=	yes

REPORTERS=	catch_reporter_automake.hpp \
		catch_reporter_bases.cpp \
		catch_reporter_bases.hpp \
		catch_reporter_compact.cpp \
		catch_reporter_compact.h \
		catch_reporter_console.cpp \
		catch_reporter_console.h \
		catch_reporter_junit.cpp \
		catch_reporter_junit.h \
		catch_reporter_multi.cpp \
		catch_reporter_multi.h \
		catch_reporter_tap.hpp \
		catch_reporter_teamcity.hpp \
		catch_reporter_xml.cpp \
		catch_reporter_xml.h

PLIST_FILES=	include/catch.hpp \
		${REPORTERS:S/^/include\//g}

do-install:
	${INSTALL_DATA} ${WRKSRC}/single_include/catch.hpp \
	    ${STAGEDIR}${PREFIX}/include
.for r in ${REPORTERS}
	${INSTALL_DATA} ${WRKSRC}/include/reporters/${r} \
	    ${STAGEDIR}${PREFIX}/include
.endfor

do-test:
	cd ${WRKSRC} && \
	    ${LOCALBASE}/bin/cmake . && ${MAKE_CMD} && ./SelfTest

.include <bsd.port.mk>
