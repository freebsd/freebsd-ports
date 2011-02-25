# New ports collection makefile for:	tinyerp
# Date created:		22 February 2006
# Whom:			Jordi Haarman
#
# $FreeBSD$
#

PORTNAME=	tinyerp-server
PORTVERSION=	3.2.1
PORTREVISION=	5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_LOCAL}			\
		http://tinyerp.org/download/sources/
MASTER_SITE_SUBDIR=	thierry
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhaarman-keyword-tinyerpPort.fd583c@projects.synantics.net
COMMENT=	Open source application ERP & CRM in Python using Postgresql

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt \
		${PYTHON_SITELIBDIR}/mx/__init__.py:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/server

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=	3.2.0

MAN1=		tinyerp-server.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/i18n
	${INSTALL_MAN} ${WRKSRC}/i18n/* ${DOCSDIR}/i18n
.endif

.include <bsd.port.mk>
