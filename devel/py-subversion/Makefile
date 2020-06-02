# Created by: thinker@branda.to
# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PORTREVISION=	0

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Python bindings for version control system

BUILD_DEPENDS=	${LOCALBASE}/include/py3c.h:devel/py3c

USES=		python
USE_PYTHON=	flavors py3kplist

PORTREVISION_114=	0
PORTREVISION_LTS=	0

SVN_BUILD_BINDINGS=	yes

.if ${FLAVOR:Upy37:Mpy3*}
WITH_SUBVERSION_VER=	114
.else
WITH_SUBVERSION_VER=	LTS
.endif

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	python

CONFIGURE_ARGS+=	--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-py check-swig-py
INSTALL_TARGET=	install-swig-py

.include <bsd.port.post.mk>
