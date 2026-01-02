PORTNAME=	odoo-addon-openupgrade-framework18
DISTVERSION=	18.0.1.0.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI/py${PYTHON_MAJOR_VER}/o/odoo-addon-openupgrade-framework/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${WHEEL_FILE}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Module to make upgrades between two major revisions
WWW=		https://github.com/OCA/OpenUpgrade \
		https://pypi.org/project/odoo-addon-openupgrade-framework

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}odoo18>=18.0.20250719<19.0.0:finance/odoo18@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openupgradelib>=0:devel/py-openupgradelib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	flavors

CONFLICTS_INSTALL=	devel/py-odoo-addon-openupgrade-framework16 \
			devel/py-odoo-addon-openupgrade-framework17

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/odoo_addon_openupgrade_framework-${DISTVERSION}

WHEEL_FILE=	odoo_addon_openupgrade_framework-${DISTVERSION}-py${PYTHON_MAJOR_VER}-none-any.whl

do-build:
	@cd ${WRKDIR} && ${PYTHON_CMD} -m wheel unpack ${DISTDIR}/${WHEEL_FILE}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
