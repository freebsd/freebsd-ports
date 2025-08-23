PORTNAME=	cvc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Circuit Validity Checker
WWW=		https://github.com/d-m-bailey/cvc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream stalled, needs EOL GCC 11 to build
EXPIRATION_DATE=2025-09-23

BUILD_DEPENDS=	pyinstaller:devel/py-pyinstaller@${PY_FLAVOR} \
		bash:shells/bash

USES=		autoreconf bison gettext-runtime gettext-tools gmake python readline shebangfix
USE_GCC=	11 # clang fails, see https://github.com/d-m-bailey/cvc/issues/239
		   # GCC 12 fails, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=266189

SHEBANG_FILES=	scripts/calibre_cvc scripts/clean_cvc_log scripts/expand_cells.py

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	d-m-bailey

MAKE_ARGS=	INTLLIBS=-lintl

.include <bsd.port.mk>
