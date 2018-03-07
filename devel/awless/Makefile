# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	awless
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.9
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Fast, powerful and easy-to-use CLI for AWS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	wallix
GH_SUBDIR=	src/github.com/wallix/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/awless
PORTDOCS=	README.md CHANGELOG.md

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o ${PORTNAME} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
