# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	${PYQTSIP_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQTSIP}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt5-
DISTNAME=	${PYQTSIP_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator

LICENSE=		SIP GPLv2 GPLv3
LICENSE_COMB=		multi
LICENSE_GROUPS_SIP=	FSF GPL OSI
LICENSE_NAME_SIP=	SIP License
LICENSE_FILE_SIP=	${FILESDIR}/LICENSE
LICENSE_PERMS_SIP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		python:3.5+ pyqt:sip
USE_PYTHON=	autoplist concurrent distutils flavors py3kplist
USE_PYQT=	#

.include <bsd.port.mk>
