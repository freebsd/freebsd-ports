# $FreeBSD$

PORTNAME=	jfrog-cli
PORTVERSION=	1.20.2
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for Artifactory

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	jfrog
GH_PROJECT=	jfrog-cli-go

PLIST_FILES=	bin/jfrog

post-patch:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/github.com/jfrog/jfrog-cli-go
	@${MV} ${WRKSRC}/jfrog-cli ${WRKSRC}/jfrog-client ${WRKSRC}/src/github.com/jfrog/jfrog-cli-go

do-build:
	@cd ${WRKSRC}/src/github.com/jfrog/jfrog-cli-go/jfrog-cli/jfrog ; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jfrog ${STAGEDIR}${PREFIX}/bin/jfrog

.include <bsd.port.mk>
