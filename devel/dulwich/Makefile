# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	dulwich
PORTVERSION=	0.9.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Pure-Python implementation of the Git file formats and protocols

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

PORTDOCS=	NEWS README introduction.txt object-store.txt protocol.txt \
		remote.txt repo.txt tag.txt
PORTEXAMPLES=	clone.py config.py diff.py

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/setup.py ${WRKSRC}/examples/*.py

post-install:
	${CP} ${WRKSRC}/docs/*.txt ${WRKSRC}/docs/tutorial/*.txt ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)
	${CP} ${WRKSRC}/examples/*.py ${WRKSRC}/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
