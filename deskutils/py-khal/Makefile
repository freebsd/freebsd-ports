# Created by: che@bein.link

PORTNAME=	khal
DISTVERSION=	0.10.5
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	CalDAV-based calendar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>1.12.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0.1.7:devel/py-atomicwrites@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=3.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-log>=0.2.0:devel/py-click-log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}icalendar>=4.0.3:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.0:devel/py-tzlocal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.3.0:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vdirsyncer>=0:deskutils/py-vdirsyncer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=		SETPROCTITLE

SETPROCTITLE_DESC=		Set the process title
SETPROCTITLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setproctitle>=0:devel/py-setproctitle@${PY_FLAVOR}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && \
	${INSTALL_DATA} khal.conf.sample ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
