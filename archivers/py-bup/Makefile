# Created by: Jos? Garc?a Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	bup
PORTVERSION=	0.29.3
CATEGORIES=	archivers python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Very efficient backup system based on the git packfile format

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylibacl>=0:security/py-pylibacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>=0:devel/py-xattr@${PY_FLAVOR} \
		git>=1.5.3.1:devel/git \
		par2cmdline>=0.4:archivers/par2cmdline
BUILD_DEPENDS=	bash:shells/bash git>=1.5.3.1:devel/git

USES=		python:2.7 gmake

PLIST_SUB=	MANDIR=${PREFIX}/share/man

OPTIONS_DEFINE=	TORNADO DOCS
OPTIONS_DEFAULT=	DOC
TORNADO_DESC=	Bup web server
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=4:www/py-tornado@${PY_FLAVOR}
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
