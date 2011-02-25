# New ports collection makefile for:	jinja
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jinja
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A fast, and easy to use stand-alone template engine

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

PYEASYINSTALL_ARCHDEP=	yes
PYEASYINSTALL_INSTALLARGS=	-N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
PYEASYINSTALL_UNINSTALLARGS=	-q -m -N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.if defined(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS}
.else
RM_OPTS=	-R
post-install:
	@${MKDIR} ${DOCSDIR}
	@${MV} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/docs/html ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/docs/txt ${DOCSDIR}/
	@${RM} ${RM_OPTS} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/docs
.endif

.include <bsd.port.mk>
