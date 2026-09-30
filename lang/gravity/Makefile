PORTNAME=	gravity
DISTVERSION=	0.9.8
CATEGORIES=	lang
PKGNAMESUFFIX=	-lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable programming language
WWW=		https://www.gravity-lang.org/ \
		https://marcobambini.github.io/gravity/ \
		https://github.com/marcobambini/gravity

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c11 cpe
CPE_VENDOR=	creolabs
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marcobambini

do-test:
	@cd ${WRKSRC} && \
		${STAGEDIR}${PREFIX}/bin/gravity -t test/unittest

# tests as of 0.9.8:
# Total Tests: 353
# Total Successes: 353
# Total Failures: 0
# Result: 100.00 %
# Time: 1008.0160 ms

.include <bsd.port.mk>
