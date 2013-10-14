# Created by: Hiroyuki Iwatsuki <don@na.rim.or.jp>
# $FreeBSD$

PKGNAMEPREFIX=	ruby-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Ruby bindings for version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 17
BROKEN=	does not build with subversion17
MASTERDIR=	${.CURDIR}/../../devel/subversion17
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USE_RUBY=	yes

SVN_BUILD_BINDINGS=yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	ruby

do-build:
	${MAKE} -C ${WRKSRC} swig-rb-lib ${MAKE_ARGS}
	${MAKE} -C ${WRKSRC} swig-rb ${MAKE_ARGS}

do-install:
	${MAKE} -C ${WRKSRC} install-swig-rb ${MAKE_ARGS}

.include <bsd.port.post.mk>
