PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Python bindings for version control system
WWW=		https://subversion.apache.org/

BUILD_DEPENDS=	${LOCALBASE}/include/py3c.h:devel/py3c

USES=		python
USE_PYTHON=	flavors py3kplist

# There is bug in python bindings Makefile
MAKE_JOBS_UNSAFE=yes

PORTREVISION_114=	2
PORTREVISION_LTS=	0

SVN_BUILD_BINDINGS=	yes

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	python

CONFIGURE_ARGS+=	--with-swig-python=${PYTHON_CMD} \
			--without-swig-perl \
			--without-swig-ruby \
			--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-py check-swig-py
INSTALL_TARGET=	install-swig-py

.include <bsd.port.post.mk>
