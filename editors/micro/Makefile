PORTNAME=	micro
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.14
PORTREVISION=	5
CATEGORIES=	editors

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Modern and intuitive terminal-based text editor
WWW=		https://micro-editor.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_HASH=	04c5770
_BUILD_DATE=	$$(date '+%B %d, %Y')
_BUILD_DEBUG=	OFF

GO_MODULE=	github.com/zyedidia/${PORTNAME}/v2
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/internal/util.Version=${_BUILD_VERSION} \
		-X ${GO_MODULE}/internal/util.CommitHash=${_BUILD_HASH} \
		-X '${GO_MODULE}/internal/util.CompileDate=${_BUILD_DATE}' \
		-X ${GO_MODULE}/internal/util.Debug=${_BUILD_DEBUG}"

PLIST_FILES=	bin/micro \
		share/applications/micro.desktop \
		share/man/man1/micro.1.gz \
		share/pixmaps/micro-logo-drop.svg \
		share/pixmaps/micro-logo-mark.svg \
		share/pixmaps/micro-logo.svg
PORTDOCS=	README.md

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_DESC=	Enable debug logging
DEBUG_VARS=	_BUILD_DEBUG=ON

pre-build:
	cd ${GO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate ./runtime

post-install:
	${INSTALL_DATA} ${WRKSRC}/assets/packaging/micro.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/assets/packaging/micro.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/*.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
