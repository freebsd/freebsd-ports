# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	dulwich
PORTVERSION=	0.8.7
CATEGORIES=	devel python
MASTER_SITES=	http://samba.org/~jelmer/${PORTNAME}/ \
		http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Pure-Python implementation of the Git file formats and protocols

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS HACKING NEWS README introduction.txt \
		object-store.txt protocol.txt remote.txt repo.txt

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

FETCH_ARGS=	-Fpr	# default '-AFpr' prevents 302 redirects by launchpad

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = ${PYTHON_CMD}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${CP} ${WRKSRC}/docs/*.txt ${WRKSRC}/docs/tutorial/*.txt ${WRKSRC}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
