# New ports collection makefile for:	jinja
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jinja2
PORTVERSION=	2.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A fast, and easy to use stand-alone template engine

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

PYEASYINSTALL_ARCHDEP=	yes
PYEASYINSTALL_INSTALLARGS=	-N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
PYEASYINSTALL_UNINSTALLARGS=	-q -m -N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
RM_OPTS=	-Rf

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
	@${RM} ${RM_OPTS} ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/docs
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
