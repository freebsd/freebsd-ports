# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googletest
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	gtest-${PORTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for writing C++ tests on a variety of platforms

LICENSE=	BSD3CLAUSE

USES=		libtool shebangfix zip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	ac_cv_path_PYTHON=python2
python_OLD_CMD=	/usr/bin/env python
python_CMD=	/usr/bin/env python2
SHEBANG_FILES=	scripts/fuse_gtest_files.py scripts/gen_gtest_pred_impl.py \
		scripts/pump.py

OPTIONS_DEFINE=	TEST

TEST_USES=	python:2,build
TEST_ALL_TARGET=check

post-patch:
# enable vendor make install again (revert r562)
	${REINPLACE_CMD} -E 's/ install-(exec|data)-local//' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gtest-config ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
