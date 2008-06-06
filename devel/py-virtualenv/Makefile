# New ports collection makefile for:	py-virtualenv
# Date created:		2007-10-10
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtualenv
PORTVERSION=	1.1
#PORTREVISION=	0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/v/virtualenv/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Virtual Python Environment builder

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

PYEASYINSTALL_INSTALLARGS=	-q -N -S ${PYTHON_SITELIBDIR} -x ${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION}
PYEASYINSTALL_UNINSTALLARGS+=	-q -m -S ${PYTHON_SITELIBDIR} -x ${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION}

PLIST_SUB=	PYEASYINSTALL_VER=${PYEASYINSTALL_VER} PYTHON_VER=${PYTHON_VER}

SUB_FILES=	${PORTNAME} ${PORTNAME}.bash
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} PYEASYINSTALL_EGG=${PYEASYINSTALL_EGG}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

pre-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} setopt -c easy_install -o exclude-scripts -s 1

post-install:
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.bash ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/support-files/
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

PYEASYINSTALL_VER!=	${MAKE} -f ${PORTSDIR}/devel/py-setuptools/Makefile -V PORTVERSION

.include <bsd.port.post.mk>
