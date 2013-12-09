# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Automated system from compile/test cycle to validate code changes

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.6.1:${PORTSDIR}/databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.6:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \
		trial:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}twistedWeb>=9.0.0:${PORTSDIR}/www/py-twistedWeb \
		${PYTHON_PKGNAMEPREFIX}twistedWords>=9.0.0:${PORTSDIR}/net-im/py-twistedWords

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USES=			twisted:run,conch,mail,web,words

MAKE_ENV+=		NO_INSTALL_REQS=1

OPTIONS_DEFINE=		TESTS
TESTS_DESC=		Install py-mock for test suite
OPTIONSFILE?=		${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=		${TEST_DEPENDS}
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

regression-test: extract
	@cd ${WRKSRC} && trial buildbot

.include <bsd.port.mk>
