# New ports collection makefile for:	decompyle
# Date created:		7 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	decompyle
PORTVERSION=	2.2.b1
CATEGORIES=	devel python
MASTER_SITES=	http://www.goebel-consult.de/decompyle/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/g}

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,${LOCALBASE}/,,g}
DISTUTIL_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

post-patch:
	${PERL} -pi -e 's,/usr/bin/env python2,${PYTHON_CMD},' \
		${WRKSRC}/scripts/decompyle

do-build:
	${DISTUTIL_CMD} build

do-install:
	${DISTUTIL_CMD} install

.include <bsd.port.mk>
