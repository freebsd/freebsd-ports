# New ports collection makefile for:   subversion-ruby
# Date Created:                4 July 2005
# Whom:                        Hiroyuki Iwatsuki <don@na.rim.or.jp>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	ruby-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Ruby bindings for version control system

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}

BROKEN=		bad plist

CONFIGURE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}

USE_RUBY=		yes

SVN_BUILD_BINDINGS=yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	ruby

do-build:
	cd ${WRKSRC} ; ${MAKE} swig-rb-lib ; ${MAKE} swig-rb

do-install:
	cd ${WRKSRC} ; ${MAKE} install-swig-rb

.include <bsd.port.post.mk>
