# $FreeBSD$

PORTNAME=	coursier
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-M12
CATEGORIES=	devel java

MAINTAINER=	jhyphenkeck@gmail.com
COMMENT=	Pure Scala Artifact Fetching

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
USE_JAVA=	yes

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/coursier

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/coursier ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
