# New ports collection makefile for:	pycount
# Date created:		Feb. 10, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	pycount
PORTVERSION=	0.0.6
CATEGORIES=	devel python
MASTER_SITES=	http://python.net/crew/gherman/playground/pycount/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.py
EXTRACT_SUFX=	#
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@lwhsu.org
COMMENT=	A very initial effort to Python code metrics

USE_DOS2UNIX=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTFILES} ${TARGETDIR}/bin/${PORTNAME}

.include <bsd.port.mk>
