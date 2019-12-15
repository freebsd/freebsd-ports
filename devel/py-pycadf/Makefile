# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	pycadf
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CADF Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=4.6.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
PORTDOCS=	*
CONFLICTS_INSTALL=	py??-pycadf-*

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.6.2:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openstackdocstheme>=1.18.1:textproc/py-openstackdocstheme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslo.config>=4.6.0:devel/py-oslo.config@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fixtures>=3.0.0:devel/py-fixtures@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslotest>=1.10.0:devel/py-oslotest@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

# Note: When updating this port please check setup.cfg if the list of *.conf
# files has been changed in some way. Sometimes there are more files in
# ${WRKSRC}/etc/pycadf but only a few of them are installed as listed in
# setup.cfg.
CONF_FILES=	ceilometer_api_audit_map.conf \
		cinder_api_audit_map.conf \
		glance_api_audit_map.conf \
		neutron_api_audit_map.conf \
		nova_api_audit_map.conf \
		trove_api_audit_map.conf \

post-patch:
	# Rename *.conf by adding a ".sample" extension to them
	@(cd ${WRKSRC}/etc/pycadf && \
		for f in *.conf; do ${MV} $${f} $${f}.sample; done)
	# Comment out *.conf files from setup.py to process them manually
	@${REINPLACE_CMD} -Ee \
		's|^(data_files)|# \1|; \
		 s|(etc/)|# \1|' \
		${WRKSRC}/setup.cfg

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/etc/pycadf &&  for f in ${CONF_FILES:C/(\.conf)$/\1.sample/g}; \
		do ${INSTALL_DATA} $${f} ${STAGEDIR}${ETCDIR}; done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
