# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	oslo.config
PORTVERSION=	7.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	7

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oslo Configuration library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.12:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.2.0:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# oslo.config 8.0.0+ requires Python 3.6+
PORTSCOUT=	limit:^7\.

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.i18n3>=3.15.3:devel/py-oslo.i18n3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR}
.endif

post-patch:
	@${GREP} -lr /etc ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|/etc|${PREFIX}&|g'

.include <bsd.port.post.mk>
