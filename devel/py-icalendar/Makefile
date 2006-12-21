# Ports collection makefile for:	py-icalendar
# Date created:			May 17, 2005
# Whom:				Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icalendar
PORTVERSION=	1.2
CATEGORIES=	devel python
MASTER_SITES=	http://codespeak.net/icalendar/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	iCalendar-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Parser and generator of iCalender files for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
