PORTNAME=	srell
DISTVERSION=	2026.11
CATEGORIES=	devel
MASTER_SITES=	https://www.akenotsuki.com/misc/${PORTNAME}/releases/
DISTNAME=	${PORTNAME}${DISTVERSION:S/./_/}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Std::regex-like regular expression template library for C++
WWW=		https://www.akenotsuki.com/misc/srell/en/

LICENSE=	BSD-2-Clause Unicode-3.0
LICENSE_COMB=	multi
LICENSE_FILE_BSD-2-Clause=	${WRKSRC}/license.txt
LICENSE_FILE_Unicode-3.0=	${WRKSRC}/license-unicode.txt

USES=		compiler:c++11-lang zip

NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^202[0-9]\.(0[1-9]\|1[0-2])$$

NO_WRKSUBDIR=	yes

PLIST_FILES=	include/srell/srell.hpp \
		include/srell/srell_ucfdata2.h \
		include/srell/srell_updata3.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.h *.hpp \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}

do-test:
	@cd ${WRKSRC}/misc && \
		${SETENVI} ${WRK_ENV} ${TEST_ENV} ${CXX} -o conftest conftest.cpp && \
		./conftest utf8c && \
		./conftest utf16 && \
		./conftest utf32 && \
		./conftest utf32w

.include <bsd.port.mk>
