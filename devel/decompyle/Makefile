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
USE_PYDISTUTILS=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,${LOCALBASE}/,,g}

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500036
	${PERL} -pi -e 's,/usr/bin/env python2,${PYTHON_CMD},' \
		${WRKSRC}/scripts/decompyle
.else
	${SED} -i.orig -e 's,/usr/bin/env python2,${PYTHON_CMD},' \
		${WRKSRC}/scripts/decompyle
.endif

.include <bsd.port.post.mk>
