# New ports collection makefile for:	pythontidy
# Date created:		Jan. 16 ,2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	pythontidy
PORTVERSION=	1.19
CATEGORIES=	devel python
MASTER_SITES=	http://www.lacusveris.com/PythonTidy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PythonTidy-${PORTVERSION}.python
EXTRACT_SUFX=	#
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Cleans up, regularizes, and reformats the text of Python scripts

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pythontidy

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}

do-patch:
	${REINPLACE_CMD} -e s,/usr/bin/python,${PYTHON_CMD}, ${WRKDIR}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTFILES} ${PREFIX}/bin/pythontidy

.include <bsd.port.mk>
