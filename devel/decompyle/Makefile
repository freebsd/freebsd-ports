# New ports collection makefile for:	decompyle
# Date created:		7 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	decompyle
PORTVERSION=	2.3
CATEGORIES=	devel python
MASTER_SITES=	http://stud.usv.ro/~rchiriliuc/asset/file/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/g}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python byte-code decompiler

USE_PYTHON=	-2.3
USE_PYDISTUTILS=	yes
USE_REINPLACE=  yes
USE_ZIP=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/env python2,${PYTHON_CMD},' \
		${WRKSRC}/scripts/decompyle

.include <bsd.port.mk>
