# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot
PORTVERSION=	0.8.12
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Continuous Integration Framework (Master)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=11.0.0:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.7:databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy07>=0.6:databases/py-sqlalchemy07 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
TEST_DEPENDS=	trial:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}txrequests>0:www/py-txrequests

USES=		python:-2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

do-test:
	@cd ${WRKSRC} && trial buildbot

.include <bsd.port.mk>
