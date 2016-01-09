# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	px
PORTVERSION=	0.9.5
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	python-p4lib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perforce p4 wrapper and Python Perforce interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTDOCS=	BUGS.txt README.txt TODO.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/data_files/d' ${WRKSRC}/setup.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
