# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	qbzr
PORTVERSION=	0.23.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/109906138/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt interface for bzr

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	bzr:devel/bzr \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${PY_FLAVOR}
RUN_DEPENDS=	bzr:devel/bzr

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gettext pyqt:4 python:2.7 qt:4
USE_PYQT=	core
USE_PYTHON=	distutils autoplist
USE_QT=		# empty
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
