PORTNAME=	git-codereview
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.0
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Command-line tool for working with Gerrit
WWW=		https://godoc.org/golang.org/x/review/git-codereview

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	review

GO_PKGNAME=	golang.org/x/review
GO_TARGET=	./git-codereview

PLIST_FILES=	bin/git-codereview

.include <bsd.port.mk>
