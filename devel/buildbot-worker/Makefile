# Created by: Frederic Praca <frederic.praca@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	buildbot-worker
PORTVERSION=	0.9.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Continuous Integration Framework (Worker)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}twisted>=14.0.1:devel/py-twisted
TEST_DEPENDS=	trial:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python:2.7
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	buildbot-worker

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

NO_ARCH=	yes

PLIST_FILES=	man/man1/buildbot-worker.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/buildbot-worker.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-test:
	${MKDIR} ${WRKDIR}/tmp
	cd ${WRKDIR}/tmp && ${PYTHON_CMD} -m twisted.trial buildbot_worker.test

.include <bsd.port.mk>
