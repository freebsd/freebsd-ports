# $FreeBSD$

PORTNAME=	git-lfs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1
CATEGORIES=	devel

MAINTAINER=	kenji@k2r.org
COMMENT=	Git extension for versioning large files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash

USES=		go gmake
USE_GITHUB=	yes
PLIST_FILES=	bin/git-lfs

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}

do-build:
	@cd ${GO_WRKSRC} && ${MKDIR} ${WRKSRC}/.tmp && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} \
	TMPDIR=${WRKSRC}/.tmp GOARCH=${GOARCH} GOOS="freebsd" \
	VERSION="" GIT_LFS_SHA="" GO=${GO_CMD} \
	sh -c "${GO_CMD} generate ${GO_PKGNAME}/commands && \
		${MAKE_CMD} bin/git-lfs"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/git-lfs ${STAGEDIR}${PREFIX}/bin/git-lfs

.include <bsd.port.mk>
