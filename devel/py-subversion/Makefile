# Created by: thinker@branda.to
# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Python bindings for version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 17
MASTERDIR=	${.CURDIR}/../../devel/subversion17
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USE_PYTHON=	yes

SVN_BUILD_BINDINGS=	yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	python

do-build:
	${MAKE} -C ${WRKSRC} swig-py-lib ${MAKE_ARGS}
	${MAKE} -C ${WRKSRC} swig-py ${MAKE_ARGS}

do-install:
	${MAKE} -C ${WRKSRC} install-swig-py ${MAKE_ARGS}

.include <bsd.port.post.mk>
