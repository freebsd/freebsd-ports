# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	openal
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	http://download.gna.org/pyopenal/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyOpenAL-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	PyOpenAL is a binding of OpenAL for Python

DIST_SUBDIR=	python
USE_OPENAL=	al alut
NO_STAGE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyOpenAL
WRKSRC=		${WRKDIR}/PyOpenAL-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-openal

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
