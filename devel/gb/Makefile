# $FreeBSD$

PORTNAME=	gb
PORTVERSION=	0.4.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Project based build tool for Go

LICENSE=	MIT

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	constabulary
GH_TUPLE=	pkg:errors:645ef00:errors/vendor/github.com/pkg/errors

PLIST_FILES=	bin/gb bin/gb-vendor

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/gb \
		./cmd/gb-vendor

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/ ; )

.include <bsd.port.mk>
