# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Continuous Integration Framework (Master)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=14.0.1:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.1:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}autobahn>=0.16.0:www/py-autobahn \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}lz4>=0:archivers/py-lz4 \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.4.0:www/py-pyjwt \
		${PYTHON_PKGNAMEPREFIX}ramlfications>0:devel/py-ramlfications \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.7:databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.6:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
TEST_DEPENDS=	trial:devel/py-twisted \
		buildbot-worker>=${PORTVERSION}:devel/buildbot-worker \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3 \
		${PYTHON_PKGNAMEPREFIX}txrequests>0:www/py-txrequests

USE_RC_SUBR=	buildbot
USES=		python:-2.7
USE_PYTHON=	autoplist distutils

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

NO_ARCH=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${PYTHON_CMD}|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete

do-test:
	@cd ${WRKSRC} && trial buildbot

.include <bsd.port.mk>
