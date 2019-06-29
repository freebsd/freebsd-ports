# $FreeBSD$

PORTNAME=	chart
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	deskutils

MAINTAINER=	mail@dbalan.in
COMMENT=	CLI tool to create quick plots

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes

PORTDOCS=	README.md
OPTIONS_DEFINE=	DOCS

GH_ACCOUNT=	marianogappa
GH_SUBDIR=	src/github.com/marianogappa/chart

GH_TUPLE=	Sirupsen:logrus:v1.0.5:logrus/src/github.com/Sirupsen/logrus \
		skratchdot:open-golang:75fb7ed:skratchdot/src/github.com/skratchdot/open-golang \
		golang:crypto:027cca1:crypto/src/golang.org/x/crypto \
		golang:sys:6c888cc:sys/src/golang.org/x/sys

PLIST_FILES=	bin/chart

do-build:
	( cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build ${BUILD_FLAGS} -o bin/chart )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chart ${STAGEDIR}${PREFIX}/bin/chart

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
