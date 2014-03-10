# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tagpy
PORTVERSION=	2013.1
PORTREVISION=	4
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python bindings for Scott Wheeler's TagLib

LICENSE=	MIT

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libtag.so:${PORTSDIR}/audio/taglib

USES=		shebangfix
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--taglib-inc-dir="${LOCALBASE}/include/taglib" \
		--taglib-lib-dir="${LOCALBASE}/lib" \
		--boost-inc-dir="${PYTHON_INCLUDEDIR},${LOCALBASE}/include" \
		--boost-lib-dir="${PYTHON_LIBDIR},${LOCALBASE}/lib" \
		--boost-python-libname="boost_python"
python_OLD_CMD=	/usr/bin/env python
python_CMD=	${PYTHON_CMD}
SHEBANG_FILES=	configure.py

USE_GCC=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
