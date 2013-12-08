# Created by: Frederic Praca <frederic.praca@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	buildbot-slave
PORTVERSION=	0.8.8
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Slave part of Buildbot, an continuous integration system

LICENSE=	GPLv2

TEST_DEPENDS:=	${RUN_DEPENDS} \
		trial:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

PROJECTHOST=		buildbot
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USES=			twisted:run,runner

MAKE_ENV+=		NO_INSTALL_REQS=1

OPTIONS_DEFINE=		TESTS
TESTS_DESC=		Install py-mock for test suite
OPTIONSFILE?=		${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

MAN1=	buildslave.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/buildslave.1 ${MANPREFIX}/man/man1

regression-test: extract
	@cd ${WRKSRC} && trial buildslave.test

.include <bsd.port.mk>
