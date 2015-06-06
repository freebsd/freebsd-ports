# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot
PORTVERSION=	0.8.12
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Continuous Integration Framework (Master)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.7:${PORTSDIR}/databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.6:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:${PORTSDIR}/devel/py-mock \
		trial:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}twistedWeb>=11.0.0:${PORTSDIR}/www/py-twistedWeb \
		${PYTHON_PKGNAMEPREFIX}twistedWords>=11.0.0:${PORTSDIR}/net-im/py-twistedWords

OPTIONS_DEFINE=		TESTS

TESTS_DESC=		Install test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python twisted:run,conch,mail,web,words
USE_PYTHON=	autoplist distutils

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

regression-test: extract
	@cd ${WRKSRC} && trial buildbot

.include <bsd.port.mk>
