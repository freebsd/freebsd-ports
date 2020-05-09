# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	editobj
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/songwrite/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	EditObj-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Create and display a Tkinter dialog box for editing any Python object

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

DIST_SUBDIR=	python
USES=		python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	EditObj
WRKSRC=		${WRKDIR}/EditObj-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-editobj

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
