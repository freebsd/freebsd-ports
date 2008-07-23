# New ports collection makefile for:	pysvn
# Date created:        22 April 2008
# Whom:                bra@fsn.hu
#
# $FreeBSD$
#

PORTNAME=	pysvn
PORTVERSION=	1.6.0
CATEGORIES=	devel
MASTER_SITES=	http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=	bra@fsn.hu
COMMENT=	Python binding for Subversion

BUILD_DEPENDS=	py${PYTHON_SUFFIX}-cxx>=5.4.1:${PORTSDIR}/devel/py-cxx
LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion \
		neon.28:${PORTSDIR}/www/neon28

USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PYDISTUTILS_NOEGGINFO=yes
PYDISTUTILS_PKGNAME=${PORTNAME}
PYDISTUTILS_CONFIGURE_TARGET=configure
PYDISTUTILS_CONFIGUREARGS=--pycxx-dir=${PYTHON_INCLUDEDIR} \
		--pycxx-src-dir=${LOCALBASE}/share/${PYTHON_VERSION}/CXX \
		--apr-inc-dir=${LOCALBASE}/include/apr-1

PLIST_SUB=	PYTHONVER=${PYTHON_VERSION:S/./_/:S/python//}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}/__init__.py \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}/_pysvn_%%PYTHONVER%%.so
PLIST_DIRS=	%%PYTHON_SITELIBDIR%%/${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/Source

do-build:
	cd ${WRKSRC} && ${MAKE}

pre-install:
	${MKDIR} ${PYTHON_SITELIBDIR}
	${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}/* ${PYTHON_SITELIBDIR}/${PORTNAME}

.include <bsd.port.mk>
