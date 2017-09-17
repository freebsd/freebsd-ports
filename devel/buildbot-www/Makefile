# Created by: Michael Gmelin <grembo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	buildbot-www
PORTVERSION=	0.9.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Continuous Integration Framework (WWW)

LICENSE=	GPLv2

MY_DEPENDS=	buildbot>=${PORTVERSION}:devel/buildbot \
		buildbot-pkg>=${PORTVERSION}:devel/buildbot-pkg \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS} \
		buildbot-console-view>=${PORTVERSION}:devel/buildbot-console-view \
		buildbot-waterfall-view>=${PORTVERSION}:devel/buildbot-waterfall-view \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity
TEST_DEPENDS=	trial:devel/py-twisted \
		buildbot-worker>=${PORTVERSION}:devel/buildbot-worker \
		${PYTHON_PKGNAMEPREFIX}mock>0.8.0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3 \
		${PYTHON_PKGNAMEPREFIX}treq>0:www/py-treq

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
