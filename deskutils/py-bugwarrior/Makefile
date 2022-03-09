# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	bugwarrior
PORTVERSION=	1.8.0
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sync issue & bug tracking systems with taskwarrior

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.5.3:devel/py-dogpile.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.9.1:devel/py-lockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}taskw>=0.8:deskutils/py-taskw@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFAULT=	BUGZILLA JIRA KEYRING PHABRICATOR TRAC
OPTIONS_GROUP=		GENERAL SERVICES
OPTIONS_GROUP_GENERAL=	KEYRING
OPTIONS_GROUP_SERVICES=	BUGZILLA JIRA PHABRICATOR TRAC

BUGZILLA_DESC=		Enable Bugzilla support
GENERAL_DESC=		General Options
JIRA_DESC=		Enabla Atlassian Jira support
KEYRING_DESC=		Enable keyring (password) support
PHABRICATOR_DESC=	Enable Phabricator support
SERVICES_DESC=		Third Party Services
TRAC_DESC=		Enable Trac support

BUGZILLA_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}python-bugzilla>=2.0.0:devel/py-python-bugzilla@${PY_FLAVOR}
JIRA_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}jira>=0.22:devel/py-jira@${PY_FLAVOR}
KEYRING_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR}
PHABRICATOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phabricator>0:devel/py-phabricator@${PY_FLAVOR}
TRAC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}offtrac>0:devel/py-offtrac@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} <= 3.7
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

do-test:
	${RM} ${WRKSRC}/tests/test_activecollab.py # Needs pandoc
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
