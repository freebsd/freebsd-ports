# Created by: Frederic Praca <frederic.praca@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	buildbot-slave
PORTVERSION=	0.8.12
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Continuous Integration Framework (Slave)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS:=	${RUN_DEPENDS} \
		trial:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	TESTS

TESTS_DESC=		Install test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python twisted:run,runner
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

PLIST_FILES=	man/man1/buildslave.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/buildslave.1 ${STAGEDIR}${MANPREFIX}/man/man1

regression-test: extract
	@cd ${WRKSRC} && trial buildslave.test

.include <bsd.port.mk>
