# ex:ts=8
# New ports collection makefile for:	py-optik
# Date created:			Nov 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	optik
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Optik-${PORTVERSION}

MAINTAINER=	ports@geeksrus.net
BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.if !defined(NOPORTDOCS)
DOCSDIR=${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
post-install:
	@${MKDIR} ${DOCSDIR}/test
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${DOCSDIR}/test
.endif

.include <bsd.port.mk>
