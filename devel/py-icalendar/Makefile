# Ports collection makefile for:	py-icalendar
# Date created:			May 17, 2005
# Whom:				Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icalendar
PORTVERSION=	0.9.3
CATEGORIES=	devel python
MASTER_SITES=	http://www.mxm.dk/products/public/ical/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	iCalendar.${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Parser and generator of iCalender files for Python

USE_PYTHON=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/iCalendar

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/iCalendar
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/iCalendar/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
