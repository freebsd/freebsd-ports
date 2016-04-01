# Created by: Frederic Praca <frederic.praca@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	buildbot-slave
PORTVERSION=	0.8.12
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Continuous Integration Framework (Slave)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=8.0.0:devel/py-twisted
TEST_DEPENDS=	trial:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python:-2.7
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	buildslave

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

NO_ARCH=	yes

PLIST_FILES=	man/man1/buildslave.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/buildslave.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-test:
	@cd ${WRKSRC} && trial buildslave.test

.include <bsd.port.mk>
