# New ports collection makefile for:	mutemix
# Date created:				2000-10-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mutemix
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://stud.fbi.fh-darmstadt.de/~koenig/pub/
EXTRACT_SUFX=	.py

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Adjusts a mixer

RUN_DEPENDS=	aumix:${PORTSDIR}/audio/aumix \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/mutemix
WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${_DISTDIR}/${DISTFILES} ${PREFIX}/bin/mutemix

.include <bsd.port.mk>
