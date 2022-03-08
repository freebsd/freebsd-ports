# Created by: Frederic Praca <frederic.praca@freebsd-fr.org>

PORTNAME=	buildbot-worker
PORTVERSION=	3.4.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Buildbot Worker Daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=17.9.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	buildbot-worker

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER}
BUILDBOT_REMOVE_ME=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/buildbot_worker

NO_ARCH=	yes

PLIST_FILES=	man/man1/buildbot-worker.1.gz
POST_PLIST+=	fix-plist

# XXX fixup plist. see:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=205056
fix-plist:
	${REINPLACE_CMD} -e 's|^${BUILDBOT_REMOVE_ME}$$||' ${TMPPLIST}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/buildbot-worker.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-test:
	${MKDIR} ${WRKDIR}/tmp
	cd ${WRKDIR}/tmp && PYTHONPATH=${WRKSRC} ${PYTHON_CMD} -m twisted.trial buildbot_worker.test

.include <bsd.port.mk>
