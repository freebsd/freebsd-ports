PORTNAME=	cvc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-4
DISTVERSIONSUFFIX=	-gd172016
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Circuit Validity Checker

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pyinstaller:devel/py-pyinstaller@${PY_FLAVOR} \
		bash:shells/bash

USES=		autoreconf bison gettext-runtime gettext-tools gmake python readline shebangfix
USE_GCC=	yes # clang fails, see https://github.com/d-m-bailey/cvc/issues/239

SHEBANG_FILES=	scripts/calibre_cvc scripts/clean_cvc_log scripts/expand_cells.py

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	d-m-bailey

MAKE_ARGS=	INTLLIBS=-lintl

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
