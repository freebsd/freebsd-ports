PORTNAME=	superhtml
PORTVERSION=	0.7.0.g20261012
CATEGORIES=	devel

MAINTAINER=	dave@freedave.net
COMMENT=	HTML Validator, Formatter and LSP
WWW=		https://zine-ssg.io/docs/superhtml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zig

USE_GITHUB=	yes
GH_ACCOUNT=	kristoff-it
# This is a little past 0.7.0 but its what zine uses, keep full hash for distcache
GH_TAGNAME=	abd86c4ba995a37b0f0559801b32b35cde8bcef9

PLIST_FILES=	bin/superhtml

post-patch:
	${REINPLACE_CMD} -e 's:%%DISTVERSION%%:${DISTVERSION}:' ${WRKSRC}/build.zig

# `make WITH_DEBUG=yes test` to test against debug build
do-test:
	cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD:S/build/build test --summary all/}

.include <bsd.port.mk>
