# ex:ts=8
# Ports collection makefile for:	py-vmaps
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vmaps
PORTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	http://snafu.freedom.org/Vmaps/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Vmaps-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Vmaps.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
