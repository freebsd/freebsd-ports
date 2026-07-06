PORTNAME=	loccount
DISTVERSION=	2.22
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/loccount/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Count source lines of code in a project
WWW=		http://www.catb.org/esr/loccount/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}

USES=		go:modules,no_targets python:build

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

USE_GITHUB=	nodefault
GH_TUPLE=	boyter:gocodewalker:v1.5.1:boyter_gocodewalker/vendor/github.com/boyter/gocodewalker \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		golang:sync:v0.12.0:golang_sync/vendor/golang.org/x/sync

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-extract:
	@${CP} ${FILESDIR}/go.mod ${WRKSRC}/go.mod
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/modules.txt

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build \
		${GO_BUILDFLAGS} -o ${PORTNAME} -ldflags='-X main.version=${PORTVERSION}'
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} asciidoctor -D. -a nofooter -b manpage ${PORTNAME}.adoc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
