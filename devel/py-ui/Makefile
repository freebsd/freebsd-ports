# ex:ts=8
# New ports collection makefile for:	py-ui
# Date created:			Jan 25, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ui
PORTVERSION=	0.93
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyui
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyui${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	\
	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl \
	${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging \
	${PYTHON_SITELIBDIR}/twisted/__init__.py:${PORTSDIR}/devel/py-twisted

USE_ZIP=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/pyui
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/pyui
	${CP} -R ${WRKSRC}/pyui/* ${PYTHON_SITELIBDIR}/pyui
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
