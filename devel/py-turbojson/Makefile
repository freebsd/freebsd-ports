# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	TurboJson
PORTVERSION=	1.3.2
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://www.turbogears.org/2.1/downloads/2.1.4/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin for TurboGears that supports json

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0:${PORTSDIR}/devel/py-PEAK-Rules
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0:${PORTSDIR}/devel/py-PEAK-Rules

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
