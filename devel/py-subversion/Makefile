# Created by: thinker@branda.to
# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PORTREVISION=	0

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Python bindings for version control system

USES+=		python:2.7
USE_PYTHON=	flavors py3kplist

PORTREVISION_113=	0
PORTREVISION_LTS=	0

SVN_BUILD_BINDINGS=	yes

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	python

CONFIGURE_ARGS+=	--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-py-lib swig-py check-swig-py
INSTALL_TARGET=	install-swig-py

.include <bsd.port.post.mk>
