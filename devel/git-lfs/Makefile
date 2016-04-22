# $FreeBSD$

PORTNAME=	git-lfs
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT

BROKEN=		fails to build

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	github
PLIST_FILES=	bin/git-lfs

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

.include <bsd.port.mk>
