# $FreeBSD$

PORTNAME=	jiri
PORTVERSION=	g2019.01.03.01
CATEGORIES=	devel
MASTER_SITES=	LOCAL/swills
DISTNAME=	${GITHASH}
DIST_SUBDIR=	jiri

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for multi-repo development

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/src/fuchsia.googlesource.com/jiri/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		ninja:devel/ninja
RUN_DEPENDS=	git:devel/git

USES=		go

GITHASH=	56b2a541f92f3bd9d28b29e1cbcb16f96d6bc6c1
TIMESTAMP=	2019-01-03T00:00:00.000000
EXTRACT_AFTER_ARGS=	-s "!^!src/fuchsia.googlesource.com/jiri/!"
PLIST_FILES=	bin/jiri

GO_PKGNAME=	fuchsia.googlesource.com/jiri
GO_TARGET=	./cmd/jiri
GO_BUILDFLAGS=	-ldflags="\
		-s -w \
		-X fuchsia.googlesource.com/jiri/version.GitCommit=${GITHASH} \
		-X fuchsia.googlesource.com/jiri/version.BuildTime=${TIMESTAMP}"

.include <bsd.port.mk>
