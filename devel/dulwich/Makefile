# Created by: Marco Broeder <marco.broeder@posteo.eu>
# $FreeBSD$

PORTNAME=	dulwich
PORTVERSION=	0.15.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@posteo.eu
COMMENT=	Python implementation of the Git file formats and protocols

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	COPYING relicensing-apachev2.txt

PORTDOCS=	AUTHORS CONTRIBUTING NEWS README.md TODO conclusion.txt \
		file-format.txt index.txt introduction.txt object-store.txt \
		performance.txt porcelain.txt protocol.txt remote.txt repo.txt tag.txt
PORTEXAMPLES=	clone.py config.py diff.py latest_change.py

USES=		cpe python:2
CPE_VENDOR=	dulwich_project
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/setup.py ${WRKSRC}/examples/*.py

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
