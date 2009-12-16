# New ports collection makefile for:	py-virtualenv
# Date created:		2007-10-10
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtualenv
PORTVERSION=	1.4.3
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Virtual Python Environment builder

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

PYEASYINSTALL_INSTALLARGS=	-q -N -S ${PYTHON_SITELIBDIR} -x ${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION}
PYEASYINSTALL_UNINSTALLARGS+=	-q -m -S ${PYTHON_SITELIBDIR} -x ${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} index.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
