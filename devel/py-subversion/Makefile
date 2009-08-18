# New ports collection makefile for:   subversion-python
# Date Created:                April 17 2004
# Whom:                        thinker@branda.to
#
# $FreeBSD$
#

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Python bindings for version control system

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}

USE_PYTHON=yes

SVN_BUILD_BINDINGS=yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	python

do-build:
	cd ${WRKSRC} ; ${MAKE} swig-py-lib ; ${MAKE} swig-py

do-install:
	cd ${WRKSRC} ; ${MAKE} install-swig-py

.include <bsd.port.post.mk>
