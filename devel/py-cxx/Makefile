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

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	CXX
PYDISTUTILS_PKGVERSION=	5.3
NO_STAGE=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

.if !defined(NOPORTDOCS)
post-install:
		@${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/Doc/PyCXX.html ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
