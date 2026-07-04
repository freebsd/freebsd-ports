PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	michaelo@apache.org
COMMENT=	Python bindings for version control system
WWW=		https://subversion.apache.org/

BUILD_DEPENDS=	${LOCALBASE}/include/py3c.h:devel/py3c

USES=		python
USE_PYTHON=	flavors py3kplist

# There is bug in python bindings Makefile
MAKE_JOBS_UNSAFE=yes

PORTREVISION_LATEST=	1
PORTREVISION_LTS=		1

SVN_BUILD_BINDINGS=	yes

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	python
EXTRA_PATCHES+= ${PATCHDIR}/extra-patch-check-swig-py314

CONFIGURE_ARGS+=	--with-swig-python=${PYTHON_CMD} \
			--without-swig-perl \
			--without-swig-ruby \
			--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-py
TEST_TARGET=	check-swig-py
INSTALL_TARGET=	install-swig-py

.include <bsd.port.post.mk>
