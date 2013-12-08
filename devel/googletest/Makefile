# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googletest
PORTVERSION=	1.5.0
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	gtest-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A framework for writing C++ tests on a variety of platforms

USES=		shebangfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	2

python_OLD_CMD=	/usr/bin/env python
python_CMD=	/usr/bin/env python2
SHEBANG_FILES=	scripts/fuse_gtest_files.py scripts/gen_gtest_pred_impl.py \
		scripts/pump.py

regression-test:
	cd ${WRKSRC}; ${MAKE} check


.include <bsd.port.mk>
