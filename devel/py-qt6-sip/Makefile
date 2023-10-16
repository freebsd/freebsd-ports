PORTNAME=	sip
PORTVERSION=	${PYQT6SIP_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT6SIP}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt6-
DISTNAME=	${PYQT6SIP_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator
WWW=		http://www.riverbankcomputing.co.uk/software/sip/

LICENSE=		SIP GPLv2 GPLv3
LICENSE_COMB=		multi
LICENSE_GROUPS_SIP=	FSF GPL OSI
LICENSE_NAME_SIP=	SIP License
LICENSE_FILE_SIP=	${FILESDIR}/LICENSE
LICENSE_PERMS_SIP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		python pyqt:6
USE_PYTHON=	autoplist concurrent distutils flavors py3kplist
USE_PYQT=	#

.include <bsd.port.mk>
