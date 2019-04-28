# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	dulwich
PORTVERSION=	0.19.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Python implementation of the Git file formats and protocols

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe python

PORTDOCS=	AUTHORS NEWS README.rst TODO conclusion.txt encoding.txt \
		file-format.txt index.txt introduction.txt object-store.txt \
		performance.txt porcelain.txt protocol.txt remote.txt repo.txt tag.txt
PORTEXAMPLES=	clone.py config.py diff.py latest_change.py

CPE_VENDOR=	dulwich_project
USE_PYTHON=	distutils autoplist concurrent

OPTIONS_DEFINE=		DOCS EXAMPLES TESTS
OPTIONS_DEFAULT=	TESTS
TESTS_DESC=		Install tests and test data

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/setup.py ${WRKSRC}/examples/*.py
.if ! ${PORT_OPTIONS:MTESTS}
	${REINPLACE_CMD} -e '/tests/d' \
		${WRKSRC}/dulwich.egg-info/SOURCES.txt \
		${WRKSRC}/MANIFEST.in
	${REINPLACE_CMD} -e "/packages=/s|'dulwich\.tests[^']*',||g" \
		${WRKSRC}/setup.py
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*.so
	${CP} ${WRKSRC}/docs/*.txt ${WRKSRC}/docs/tutorial/*.txt ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)
	${CP} ${WRKSRC}/examples/*.py ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
