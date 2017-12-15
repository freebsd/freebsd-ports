# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bugwarrior
PORTVERSION=	1.3.0
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Sync issue & bug tracking systems with taskwarrior

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twiggy>0:devel/py-twiggy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}taskw>=0.8:deskutils/py-taskw@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.2:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.5.3:devel/py-dogpile.cache@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.9.1:devel/py-lockfile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${FLAVOR}

OPTIONS_DEFINE=		BUGZILLA JIRA PHABRICATOR
OPTIONS_DEFAULT=	BUGZILLA PHABRICATOR

BUGZILLA_DESC=			Enable Bugzilla support
BUGZILLA_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}python-bugzilla>0:devel/py-python-bugzilla@${FLAVOR}

JIRA_DESC=			Enabla Atlassian Jira support
JIRA_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}jira>0:devel/py-jira@${FLAVOR}

PHABRICATOR_DESC=		Enable Phabricator support
PHABRICATOR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phabricator>0:devel/py-phabricator@${FLAVOR}

TRAC_DESC=			Enable Trac support
TRAC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}offtrac>0:devel/py-offtrac@${FLAVOR}

USES=		python:-2.7
USE_PYTHON=	autoplist concurrent distutils

do-test:
	${RM} ${WRKSRC}/tests/test_activecollab.py # Needs pandoc
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
