# New ports collection makefile for:	decompyle
# Date created:		7 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	decompyle
PORTVERSION=	2.2.b1
CATEGORIES=	devel python
MASTER_SITES=	http://www.crazy-compilers.com/decompyle/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/g}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python byte-code decompiler

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=  yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/env python2,${PYTHON_CMD},' \
		${WRKSRC}/scripts/decompyle

.include <bsd.port.mk>
