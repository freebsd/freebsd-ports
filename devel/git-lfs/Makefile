# $FreeBSD$

PORTNAME=	git-lfs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
CATEGORIES=	devel

MAINTAINER=	kenji@k2r.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash

USES=		go
USE_GITHUB=	yes
PLIST_FILES=	bin/git-lfs

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

# see https://github.com/git-lfs/git-lfs/wiki/Installation

do-build:
	@cd ${WRKSRC} && ${MKDIR} ${WRKSRC}/.tmp && ${SETENV} ${MAKE_ENV} ${GO_ENV} TMPDIR=${WRKSRC}/.tmp script/bootstrap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/git-lfs ${STAGEDIR}${PREFIX}/bin/git-lfs

.include <bsd.port.mk>
