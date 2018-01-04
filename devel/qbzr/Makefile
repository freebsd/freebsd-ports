# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	qbzr
PORTVERSION=	0.23.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/109906138/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt interface for bzr

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:devel/bzr \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${FLAVOR}
RUN_DEPENDS=	bzr:devel/bzr

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gettext pyqt:4 python:2.7
USE_PYQT=	core
USE_PYTHON=	distutils autoplist
USE_QT4=	# empty
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
