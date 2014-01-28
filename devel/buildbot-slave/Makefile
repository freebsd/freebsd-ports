# Created by: Frederic Praca <frederic.praca@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	buildbot-slave
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Buildbot Continuous Integration Framework (Slave)

LICENSE=	GPLv2

TEST_DEPENDS:=	${RUN_DEPENDS} \
		trial:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install py-mock for test suite

USES=			twisted:run,runner
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

MAKE_ENV+=		NO_INSTALL_REQS=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

PLIST_FILES=	man/man1/buildslave.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/buildslave.1 ${STAGEDIR}${MANPREFIX}/man/man1

regression-test: extract
	@cd ${WRKSRC} && trial buildslave.test

.include <bsd.port.mk>
