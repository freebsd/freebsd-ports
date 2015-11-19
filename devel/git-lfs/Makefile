# $FreeBSD$

PORTNAME=	git-lfs
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	github
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
PLIST_FILES=	bin/git-lfs

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
