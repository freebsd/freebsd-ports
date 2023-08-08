PORTNAME=	sip
PORTVERSION=	${PYQT5SIP_VERSION}
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT5SIP}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt5-
DISTNAME=	${PYQT5SIP_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator
WWW=		http://www.riverbankcomputing.co.uk/software/sip/

LICENSE=		SIP GPLv2 GPLv3
LICENSE_COMB=		multi
LICENSE_GROUPS_SIP=	FSF GPL OSI
LICENSE_NAME_SIP=	SIP License
LICENSE_FILE_SIP=	${FILESDIR}/LICENSE
LICENSE_PERMS_SIP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		python pyqt:sip
USE_PYTHON=	autoplist concurrent distutils flavors py3kplist
USE_PYQT=	#

.include <bsd.port.mk>
