# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	px
PORTVERSION=	0.9.5
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	python-p4lib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perforce p4 wrapper and Python Perforce interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	BUGS.txt README.txt TODO.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/data_files/d' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
