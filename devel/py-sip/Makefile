# Created by: nbm
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	${SIP_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_SIP}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${SIP_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator

LICENSE=		SIP GPLv2 GPLv3
LICENSE_COMB=		multi
LICENSE_NAME_SIP=	SIP License
LICENSE_GROUPS_SIP=	FSF GPL OSI
LICENSE_PERMS_SIP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_SIP=	${WRKSRC}/LICENSE 
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE-GPL2
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python:3.5+ pyqt:sip
USE_PYTHON=	autoplist concurrent distutils flavors py3kplist
USE_PYQT=	#

.include <bsd.port.mk>
