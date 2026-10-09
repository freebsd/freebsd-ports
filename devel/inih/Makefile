PORTNAME=	inih
DISTVERSIONPREFIX=	r
DISTVERSION=	62
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple .INI file parser written in C
WWW=		https://github.com/benhoyt/inih

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	bash:shells/bash

USES=		meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	benhoyt

test-quick: stage
	@${ECHO} "==> Running smoke test"
	@cd ${TEST_WRKSRC} && \
		${CC} ${FILESDIR}/test-main.c -I${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/lib/libinih.so -o test && \
		./test ${FILESDIR}/test-config.ini
	@${ECHO} "... smoke test completed successfully"

# tests as of 62:
# Ok:                16
# Fail:              0

.include <bsd.port.mk>
