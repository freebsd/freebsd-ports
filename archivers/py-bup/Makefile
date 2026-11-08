PORTNAME=	bup
PORTVERSION=	0.33.10
CATEGORIES=	archivers python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Very efficient backup system based on the git packfile format
WWW=		https://bup.github.io

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		git>1.5.6:devel/git
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylibacl>0:security/py-pylibacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>0:devel/py-xattr@${PY_FLAVOR} \
		bash:shells/bash \
		git>1.5.6:devel/git \
		par2cmdline>0.4:archivers/par2cmdline

USES=		gettext-runtime gmake python readline shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist

SHEBANG_FILES=	lib/cmd/bup-import-rdiff-backup lib/cmd/bup-import-rsnapshot \
		test/ext/test-sparse-files
# 0.33+ selects Python via python-config, not a bare PYTHON=
CONFIGURE_ENV+=	BUP_PYTHON_CONFIG=${PYTHON_CMD}-config
MAKE_ARGS=	PANDOC="${PANDOC}"
MAKE_ENV+=	BUP_PYTHON_CONFIG=${PYTHON_CMD}-config
TEST_TARGET=	test

PLIST_SUB=	MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=		DOCS TORNADO
DOCS_DESC=		Build man files and html documentation
TORNADO_DESC=		Bup web server
DOCS_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc
DOCS_VARS=		PANDOC=pandoc
DOCS_VARS_OFF=		PANDOC=""
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>4:www/py-tornado@${PY_FLAVOR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/lib/bup/cmd \
		${STAGEDIR}${PREFIX}/lib/bup/bup \
		${STAGEDIR}${PREFIX}/lib/bup/web/static
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		DESTDIR=${STAGEDIR} PREFIX=${PREFIX} MAKEFLAGS= \
		${MAKE_CMD} ${MAKE_ARGS:NDESTDIR=*:NPREFIX=*} install

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/bup/cmd/bup
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/bup/bup/*.so
	${LN} -sf ../lib/bup/cmd/bup ${STAGEDIR}${PREFIX}/bin/bup

.include <bsd.port.mk>
