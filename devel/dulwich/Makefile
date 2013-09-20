# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	dulwich
PORTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.samba.org/~jelmer/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Pure-Python implementation of the Git file formats and protocols

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual


PORTDOCS=	AUTHORS HACKING NEWS README introduction.txt \
		object-store.txt protocol.txt remote.txt repo.txt tag.txt

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${CP} ${WRKSRC}/docs/*.txt ${WRKSRC}/docs/tutorial/*.txt ${WRKSRC}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
