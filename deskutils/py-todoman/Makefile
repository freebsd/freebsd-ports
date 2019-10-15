# $FreeBSD$

PORTNAME=	todoman
DISTVERSION=	3.7.0
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andreas@bilke.org
COMMENT=	Simple CalDAV-based todo manager

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>0:devel/py-atomicwrites@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-log>=0.2.1:devel/py-click-log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0&&<8.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>0:devel/py-humanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}icalendar>=4.0.3:devel/py-icalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>0:devel/py-parsedatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>0:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vdirsyncer>0:deskutils/py-vdirsyncer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

PLIST_FILES=	${EXAMPLESDIR}/todoman.conf.sample \
		share/zsh/site-functions/_todoman

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/zsh/_todo \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_todoman
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} todoman.conf.sample ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
