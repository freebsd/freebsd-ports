# New ports collection makefile for:	py-tagpy
# Date created:		2007-01-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tagpy
PORTVERSION=	0.94.7
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python bindings for Scott Wheeler's TagLib

LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs \
		tag.1:${PORTSDIR}/audio/taglib

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--taglib-inc-dir="${LOCALBASE}/include/taglib" \
		--taglib-lib-dir="${LOCALBASE}/lib" \
		--boost-inc-dir="${PYTHON_INCLUDEDIR},${LOCALBASE}/include" \
		--boost-lib-dir="${PYTHON_LIBDIR},${LOCALBASE}/lib" \
		--boost-python-libname="boost_python"

USE_GCC=	4.3+
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
