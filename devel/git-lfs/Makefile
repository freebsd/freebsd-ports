# $FreeBSD$

PORTNAME=	git-lfs
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	kenji@k2r.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		go
USE_GITHUB=	yes
PLIST_FILES=	bin/git-lfs

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

# see https://github.com/git-lfs/git-lfs/wiki/Installation

do-build:
	cd ${WRKSRC} && ${MKDIR} ${WRKSRC}/.tmp && TMPDIR=${WRKSRC}/.tmp script/bootstrap

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/git-lfs ${STAGEDIR}${PREFIX}/bin/git-lfs

.include <bsd.port.mk>
