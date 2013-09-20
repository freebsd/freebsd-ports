# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	editobj
PORTVERSION=	0.5.7
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/songwrite/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	EditObj-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Create and display a Tkinter dialog box for editing any Python object

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	EditObj
WRKSRC=		${WRKDIR}/EditObj-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-editobj

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
