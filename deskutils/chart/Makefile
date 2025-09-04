PORTNAME=	chart
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
PORTREVISION=	30
CATEGORIES=	deskutils

MAINTAINER=	mail@dbalan.in
COMMENT=	CLI tool to create quick plots
WWW=		https://marianogappa.github.io/chart/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	marianogappa
GH_SUBDIR=	src/github.com/marianogappa/chart

GH_TUPLE=	Sirupsen:logrus:v1.0.5:logrus/vendor/github.com/Sirupsen/logrus \
		skratchdot:open-golang:75fb7ed:skratchdot/vendor/github.com/skratchdot/open-golang \
		golang:crypto:027cca1:crypto/vendor/golang.org/x/crypto \
		golang:sys:6c888cc:sys/vendor/golang.org/x/sys

PORTDOCS=	README.md
PLIST_FILES=	bin/chart

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
