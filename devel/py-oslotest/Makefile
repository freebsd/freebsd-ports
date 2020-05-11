# $FreeBSD$

PORTNAME=	oslotest
DISTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Oslo test framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fixtures>=3.0.0:devel/py-fixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-subunit>=1.0.0:devel/py-python-subunit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testrepository>=0.0.18:devel/py-testrepository@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=2.2.0:devel/py-testtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mox3>=0.20.0:devel/py-mox3@${PY_FLAVOR} \
		bash>0:shells/bash

USES=		python shebangfix
USE_PYTHON=	distutils autoplist
SHEBANG_FILES=	tools/oslo_debug_helper \
		tools/oslo_run_cross_tests \
		tools/oslo_run_pre_release_tests

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx18>=1.6.2:textproc/py-sphinx18@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openstackdocstheme>=1.18.1:textproc/py-openstackdocstheme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fixtures>=3.0.0:devel/py-fixtures@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}debtcollector>=0:devel/py-debtcollector@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mox3>=0.20.0:devel/py-mox3@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}os-client-config1>=1.28.0:devel/py-os-client-config1@${PY_FLAVOR}
DOCS_BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}os-client-config1>=1.28.0:devel/py-os-client-config1@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslo.config7>=5.2.0:devel/py-oslo.config7@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}os-client-config>=1.28.0:devel/py-os-client-config@${PY_FLAVOR}
DOCS_BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}os-client-config>=1.28.0:devel/py-os-client-config@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
