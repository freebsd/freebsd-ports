# Created by: Hiroyuki Iwatsuki <don@na.rim.or.jp>
# $FreeBSD$

PKGNAMEPREFIX=	ruby-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Ruby bindings for version control system

BROKEN_powerpc64=	fails to compile: swigutil_rb.c: 'ruby_errinfo' undeclared

USE_RUBY=	yes

PORTREVISION_111=	0
PORTREVISION_19=	0

SVN_BUILD_BINDINGS=	yes

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	ruby

CONFIGURE_ARGS+=	--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-rb-lib swig-rb
INSTALL_TARGET=	install-swig-rb

.include <bsd.port.post.mk>
