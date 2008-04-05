# New ports collection makefile for:	py-tagpy
# Date created:		2007-01-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tagpy
PORTVERSION=	0.93
#PORTREVISION=	0
CATEGORIES=	audio python
MASTER_SITES=	http://news.tiker.net/news.tiker.net/download/software/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python bindings for Scott Wheeler's TagLib

LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python \
		tag.5:${PORTSDIR}/audio/taglib

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--taglib-inc-dir="${LOCALBASE}/include/taglib" \
		--taglib-lib-dir="${LOCALBASE}/lib" \
		--boost-inc-dir="${PYTHON_INCLUDEDIR}\", \"${LOCALBASE}/include" \
		--boost-lib-dir="${PYTHON_LIBDIR}\", \"${LOCALBASE}/lib" \
		--boost-python-lib-names="boost_python"

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
