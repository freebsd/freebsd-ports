# New ports collection makefile for:	mutemix
# Date created:				2000-10-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mutemix
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://stud.fbi.fh-darmstadt.de/~koenig/pub/
EXTRACT_SUFX=	.py

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	aumix:${PORTSDIR}/audio/aumix \
		${LOCALBASE}/lib/python1.5/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKDIR}

pre-install:
	${ECHO} "bin/mutemix" > ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${_DISTDIR}/${DISTFILES} ${PREFIX}/bin/mutemix

.include <bsd.port.mk>
