# New ports collection makefile for:	py-editobj
# Date created:				2005-10-05
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	editobj
PORTVERSION=	0.5.7
CATEGORIES=	graphics python
MASTER_SITES=	http://download.gna.org/songwrite/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	EditObj-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Create and display a Tkinter dialog box for editing any Python object

DIST_SUBDIR=	python
USE_GZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/EditObj-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/py-editobj

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
