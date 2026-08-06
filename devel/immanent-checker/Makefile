PORTNAME=	immanent-checker
DISTVERSION=	0.42
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.p.variablis.de/api/v4/projects/open-source%2Fimmanent-checker/packages/generic/${PORTNAME}/${DISTVERSION}/:phar \
		https://gitlab.p.variablis.de/open-source/immanent-checker/-/raw/${DISTVERSION}/man/man1/:manpage
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTFILES=	immanent-checker-${DISTVERSION}:phar \
		immanent-parser-${DISTVERSION}:phar \
		immanent-checker.1:manpage
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Project structure and source expectation checker
WWW=		https://gitlab.p.variablis.de/open-source/immanent-checker

USES=		php:flavors
USE_PHP=	phar tokenizer

CONFLICTS_INSTALL=	php*-immanent-checker

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/immanent-checker \
		bin/immanent-parser \
		share/man/man1/immanent-checker.1.gz

do-install:
	${INSTALL_SCRIPT} ${_DISTDIR}/immanent-checker-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/immanent-checker
	${INSTALL_SCRIPT} ${_DISTDIR}/immanent-parser-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/immanent-parser
	${INSTALL_MAN} ${_DISTDIR}/immanent-checker.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
