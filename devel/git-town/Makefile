# $FreeBSD$

PORTNAME=	git-town
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Git extension for generic, high-level git workflow support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go
RUN_DEPENDS=	git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	Originate
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
