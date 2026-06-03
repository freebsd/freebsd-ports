PORTNAME=	c
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
CATEGORIES=	lang

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tool to compile and run C programs like a shell script
WWW=		https://github.com/ryanmjacobs/c

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ryanmjacobs

SHEBANG_FILES=	${WRKSRC}/tests/test.sh

NO_ARCH=	yes
NO_BUILD=	yes

TEST_WRKSRC=	${WRKSRC}/tests/

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}/

do-test:
	(cd ${TEST_WRKSRC} && ./test.sh)

.include <bsd.port.mk>
