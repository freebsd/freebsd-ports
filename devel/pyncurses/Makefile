# New ports collection makefile for:	pyncurses
# Date created:				Tue May 16 22:15:11 PDT 2000
# Whom:					adsharma@sharams.dhs.org
#
# $FreeBSD$
#

PORTNAME=	py-ncurses
PORTVERSION=	0.3
CATEGORIES=	devel python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-//}
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	adsharma@sharmas.dhs.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
