# Created by: Hiroyuki Iwatsuki <don@na.rim.or.jp>
# $FreeBSD$

PKGNAMEPREFIX=	ruby-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Ruby bindings for version control system

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2012-05-02

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USE_RUBY=		yes

SVN_BUILD_BINDINGS=yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	ruby

do-build:
	cd ${WRKSRC} ; ${MAKE} swig-rb-lib ; ${MAKE} swig-rb

do-install:
	cd ${WRKSRC} ; ${MAKE} install-swig-rb

.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif

.include <bsd.port.post.mk>
