PORTNAME=	bup
PORTVERSION=	0.32
CATEGORIES=	archivers python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Very efficient backup system based on the git packfile format

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylibacl>0:security/py-pylibacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>0:devel/py-xattr@${PY_FLAVOR} \
		git>1.5.6:devel/git \
		par2cmdline>0.4:archivers/par2cmdline
BUILD_DEPENDS=	bash:shells/bash \
		git>1.5.6:devel/git
RUN_DEPENDS=	bash:shells/bash

USES=		gmake python:3.6+ shebangfix
USE_PYTHON=	autoplist
SHEBANG_FILES=	test/ext/test-sparse-files lib/cmd/import-rdiff-backup-cmd.sh

PLIST_SUB=	MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=	TORNADO DOCS
OPTIONS_DEFAULT=	DOC
TORNADO_DESC=	Bup web server
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>4:www/py-tornado@${PY_FLAVOR}
DOCS_DESC=	Build man files and html documentation
DOCS_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
DOCS_VARS=		PANDOC=pandoc
DOCS_VARS_OFF=		PANDOC=""

TEST_TARGET=		test
MAKE_ARGS=	PANDOC="${PANDOC}"
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/bup/bup/*.so

.include <bsd.port.mk>
