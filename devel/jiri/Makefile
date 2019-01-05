# $FreeBSD$

PORTNAME=	jiri
PORTVERSION=	g2019.01.03.01
CATEGORIES=	devel
MASTER_SITES=	https://fuchsia.googlesource.com/jiri/+archive/
DISTNAME=	${GITHASH}
DIST_SUBDIR=	jiri

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for multi-repo development

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/go/src/fuchsia.googlesource.com/jiri/LICENSE

BUILD_DEPENDS=	go:lang/go \
		cmake:devel/cmake \
		ninja:devel/ninja
RUN_DEPENDS=	git:devel/git

GITHASH=	56b2a541f92f3bd9d28b29e1cbcb16f96d6bc6c1
TIMESTAMP=	2019-01-03T00:00:00.000000
EXTRACT_AFTER_ARGS=	-s "!^!${DISTNAME}/go/src/fuchsia.googlesource.com/jiri/!"
PLIST_FILES=	bin/jiri

pre-extract:
	@${MKDIR} ${WRKSRC}

do-build:
	cd ${WRKSRC}/go/src/fuchsia.googlesource.com/jiri && \
		${SETENV} GOPATH=${WRKSRC}/go \
			go build -ldflags "-s -w -X \"fuchsia.googlesource.com/jiri/version.GitCommit=${GITHASH}\" -X \"fuchsia.googlesource.com/jiri/version.BuildTime=${TIMESTAMP}\"" -a -o jiri fuchsia.googlesource.com/jiri/cmd/jiri

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/go/src/fuchsia.googlesource.com/jiri/jiri ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
