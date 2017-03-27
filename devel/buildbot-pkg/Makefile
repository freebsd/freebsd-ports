# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot-pkg
PORTVERSION=	0.9.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Continuous Integration Framework (packaging)

LICENSE=	GPLv2

MY_DEPENDS=	buildbot>=0.9.4:devel/buildbot
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}
TEST_DEPENDS=	trial:devel/py-twisted \
		buildbot-worker>=0.9.4:devel/buildbot-worker \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3 \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity \
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
