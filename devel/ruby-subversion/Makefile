# Created by: Hiroyuki Iwatsuki <don@na.rim.or.jp>
# $FreeBSD$

PKGNAMEPREFIX=	ruby-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Ruby bindings for version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
MASTERDIR=	${.CURDIR}/../../devel/subversion18
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USE_RUBY=	yes

SVN_BUILD_BINDINGS=	yes
SVN_BUILD_ADDONS=	yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	ruby

CONFIGURE_ARGS+=	--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-rb-lib swig-rb
INSTALL_TARGET=	install-swig-rb

.include <bsd.port.post.mk>
