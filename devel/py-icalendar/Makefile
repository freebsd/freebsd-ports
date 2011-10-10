# Ports collection makefile for:	py-icalendar
# Date created:			May 17, 2005
# Whom:				Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icalendar
PORTVERSION=	2.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Parser and generator of iCalender files for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${WRKSRC}/docs/changelog.rst ${DOCSDIR}/
.endif

.include <bsd.port.mk>
