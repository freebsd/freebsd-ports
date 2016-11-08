# $FreeBSD$

PORTNAME=	git-lfs
PORTVERSION=	1.4.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES=	GH GHC
PKGNAMEPREFIX=	go-

MAINTAINER=	kenji@k2r.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	github
PLIST_FILES=	bin/git-lfs

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

# see https://github.com/github/git-lfs/wiki/Installation

do-build:
	cd ${WRKSRC} && ${MKDIR} ${WRKSRC}/.tmp && TMPDIR=${WRKSRC}/.tmp script/bootstrap

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/git-lfs ${STAGEDIR}${PREFIX}/bin/git-lfs

.include <bsd.port.mk>
