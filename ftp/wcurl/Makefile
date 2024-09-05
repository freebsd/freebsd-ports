PORTNAME=	wcurl
DISTVERSION=	2024.07.10
CATEGORIES=	ftp net www

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Simple wrapper around curl to easily download files
WWW=		https://curl.se/wcurl/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl>=7.46.0:ftp/curl
TEST_DEPENDS=	shunit2:devel/shunit2

USE_GITHUB=	yes
GH_ACCOUNT=	curl

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/wcurl \
		share/man/man1/wcurl.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wcurl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wcurl.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-test:
	cd ${WRKSRC} && ./tests/tests.sh

.include <bsd.port.mk>
