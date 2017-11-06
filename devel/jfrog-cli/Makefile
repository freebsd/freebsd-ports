# $FreeBSD$

PORTNAME=	jfrog-cli
PORTVERSION=	1.6.0
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
.for src in .gitignore CONTRIBUTING.md Jenkinsfile LICENSE README.md \
	artifactory bintray getCli.sh jfrog missioncontrol testsdata utils xray
	@${MV} ${WRKSRC}/${src} ${WRKSRC}/src/github.com/jfrogdev/jfrog-cli-go
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/jfrogdev/jfrog-cli-go ; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jfrog ${STAGEDIR}${PREFIX}/bin/jfrog

.include <bsd.port.mk>
