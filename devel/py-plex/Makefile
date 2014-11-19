# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	plex
PORTVERSION=	1.1.5
CATEGORIES=	devel python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Plex/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Plex-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lexical Analysis Module for Python

USES=		python
USE_PYTHON=	distutils autoplist

NO_WRKSUBDIR=	yes
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

post-extract:
	${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${FILESDIR}/setup.py \
		> ${WRKSRC}/setup.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ./* ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ./* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
