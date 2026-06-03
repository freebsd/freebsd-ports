PORTNAME=	superhtml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	devel

MAINTAINER=	dave@freedave.net
COMMENT=	HTML Validator, Formatter and LSP
WWW=		https://zine-ssg.io/docs/superhtml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zig:015

USE_GITHUB=	yes
GH_ACCOUNT=	kristoff-it
GH_PROJECT=	${PORTNAME}

PLIST_FILES=	bin/superhtml

ZIG_TUPLE=	known_folders:github.com/ziglibs/known-folders/archive/ab5cf5feb936fa3b72c95d3ad0c0c6779.tar.gz:known_folders-0.0.0-Fy-PJtTTAADUOhGKM0sxzG4eMkNQxRvx9e5dfHVyaeA3 \
		lsp_kit:github.com/zigtools/lsp-kit/archive/fe98e895ca3bd1b39965ab30f0f252f7b.tar.gz:lsp_kit-0.1.0-bi_PLzAyCgClDh8_M0U9Q50ysdsQBuRuBTZfwg6rZPd6 \
		scripty:github.com/kristoff-it/scripty/archive/50dbab8945440089384f26ec165d870c2.tar.gz:scripty-0.1.0-LKK5O7v4AADWWXuFcTJky_5sY12tmw3kRi3k2wkpfxAX \
		tracy:github.com/kristoff-it/tracy/archive/67d2d89e351048c76fc6d161e0ac09d8a.tar.gz:tracy-0.0.0-4Xw-1pwwAABTfMgoDP1unCbZDZhJEfict7XCBGF6IdIn

# `make WITH_DEBUG=yes test` to test against debug build
do-test:
	cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD:S/build/build test --summary all/}

.include <bsd.port.mk>
