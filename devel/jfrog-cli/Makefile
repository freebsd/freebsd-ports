# $FreeBSD$

PORTNAME=	jfrog-cli
PORTVERSION=	1.13.1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for Artifactory

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	JFrogDev
GH_PROJECT=	jfrog-cli-go

PLIST_FILES=	bin/jfrog

post-extract:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/github.com/jfrogdev/jfrog-cli-go
	@${MV} ${WRKSRC}/jfrog-cli ${WRKSRC}/jfrog-client ${WRKSRC}/src/github.com/jfrogdev/jfrog-cli-go

do-build:
	@cd ${WRKSRC}/src/github.com/jfrogdev/jfrog-cli-go ; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jfrog ${STAGEDIR}${PREFIX}/bin/jfrog

.include <bsd.port.mk>
