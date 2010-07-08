# New ports collection makefile for:	py-tarfile
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	tarfile
PORTVERSION=	0.8.0
CATEGORIES=	archivers python
MASTER_SITES=	http://www.gustaebel.de/lars/tarfile/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library for reading and writing tarballs

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DEPRECATED=	all development activity in this port has been merged into mainline python after 2.4

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 230
PLIST_SUB+=	NO_PY23=""
.else
PLIST_SUB+=	NO_PY23="@comment "
.endif

.include <bsd.port.post.mk>
