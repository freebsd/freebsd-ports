# $FreeBSD$

PORTNAME=	gb
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Project based build tool for Go

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	constabulary

PLIST_FILES=	bin/gb bin/gb-vendor

PORTDOCS=	README.md

STRIP=		# stripping can break go binaries
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./...

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/* ${STAGEDIR}/${LOCALBASE}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/ ; )

.include <bsd.port.mk>
