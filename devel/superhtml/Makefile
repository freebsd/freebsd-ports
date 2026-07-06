PORTNAME=	superhtml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	devel

MAINTAINER=	dave@freedave.net
COMMENT=	HTML Validator, Formatter and LSP
WWW=		https://zine-ssg.io/docs/superhtml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zig

USE_GITHUB=	yes
GH_ACCOUNT=	kristoff-it
GH_PROJECT=	${PORTNAME}

PLIST_FILES=	bin/superhtml

# `make WITH_DEBUG=yes test` to test against debug build
do-test:
	cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD:S/build/build test --summary all/}

.include <bsd.port.mk>
