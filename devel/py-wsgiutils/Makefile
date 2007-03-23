# New ports collection makefile for:	py-wsgiutils
# Date created:         		25 June 2006
# Whom:                 		Jordi Haarman
#
# $FreeBSD$
#

PORTNAME=	wsgiutils
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel textproc www python
MASTER_SITES=	http://www.owlfish.com/software/wsgiutils/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WSGIUtils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility libraries for development of simple WSGI programs

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PLIST_FILES=	${PYTHON_SITELIBDIR:S,${PREFIX}/,,}/${PYWSGIUTILS_EGG}
PLIST_SUB=	PYWSGIUTILS_EGG="${PYWSGIUTILS_EGG}"

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	EGG="WSGIUtils==${PORTVERSION}" \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

PYWSGIUTILS_EGG=	WSGIUtils-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
