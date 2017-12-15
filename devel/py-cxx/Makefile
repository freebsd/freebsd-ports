# Created by: ijliao
# $FreeBSD$

PORTNAME=	cxx
PORTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/CXX/PyCXX%20V${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycxx-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Make it easier to extend Python with C++

USES=		python:2.7
USE_PYTHON=	distutils pythonprefix
PYDISTUTILS_PKGNAME=	CXX
PYDISTUTILS_PKGVERSION=	5.3

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/PyCXX.html ${STAGEDIR}${DOCSDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
