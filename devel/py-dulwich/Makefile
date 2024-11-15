PORTNAME=	dulwich
DISTVERSION=	0.21.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of the Git file formats and protocols
WWW=		https://www.dulwich.io/

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.25:net/py-urllib3@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	dulwich_project
USE_PYTHON=	autoplist concurrent pep517

PORTDOCS=	AUTHORS NEWS README.rst TODO conclusion.txt encoding.txt \
		file-format.txt index.txt introduction.txt object-store.txt \
		performance.txt porcelain.txt protocol.txt remote.txt repo.txt tag.txt
PORTEXAMPLES=	clone.py config.py diff.py latest_change.py

OPTIONS_DEFINE=	DOCS EXAMPLES FASTIMPORT PARAMIKO TEST
OPTIONS_DEFAULT=TEST

FASTIMPORT_DESC=	Enable fastimport support
PARAMIKO_DESC=	Enable paramiko SSH2 protocol support

FASTIMPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastimport>=0:devel/py-fastimport@${PY_FLAVOR}
PARAMIKO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/setup.py ${WRKSRC}/examples/*.py

post-patch-TEST-off:
	${REINPLACE_CMD} -e '/tests/d' \
		${WRKSRC}/dulwich.egg-info/SOURCES.txt \
		${WRKSRC}/MANIFEST.in
	${REINPLACE_CMD} -e "/packages=/s|'dulwich\.tests[^']*',||g" \
		${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*.so

post-install-DOCS-on:
	${CP} ${WRKSRC}/docs/*.txt ${WRKSRC}/docs/tutorial/*.txt ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

post-install-EXAMPLES-on:
	${CP} ${WRKSRC}/examples/*.py ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
