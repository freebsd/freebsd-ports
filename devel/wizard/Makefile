# ex:ts=8
# Ports collection makefile for:	wizard
# Date created:			Jan 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wizard
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	http://www.zolera.com/resources/opensrc/wizard/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.if !defined(NOPORTDOCS)
post-install:
	@${CP} -R ${WRKSRC}/doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
