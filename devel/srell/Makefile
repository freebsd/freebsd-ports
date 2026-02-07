PORTNAME=	srell
DISTVERSION=	4.070
CATEGORIES=	devel
MASTER_SITES=	https://www.akenotsuki.com/misc/${PORTNAME}/releases/
DISTNAME=	${PORTNAME}${DISTVERSION:S/./_/}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Std::regex-like regular expression template library for C++
WWW=		https://www.akenotsuki.com/misc/srell/en/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		compiler:c++11-lang zip

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && \
		${INSTALL_DATA} srell.hpp \
				srell_ucfdata2.h \
				srell_updata3.h \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme_*.txt ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC}/misc && \
		${SETENVI} ${WRK_ENV} ${TEST_ENV} ${CXX} -o conftest conftest.cpp && \
		./conftest utf8c && \
		./conftest utf16 && \
		./conftest utf32 && \
		./conftest utf32w

.include <bsd.port.mk>
