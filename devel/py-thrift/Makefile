# New ports collection makefile for:	thrift
# Date created:	   30 Nov 2007
# Whom:		   Jon M. Dugan <jdugan@x1024.net>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	20070917
CATEGORIES=	devel python
PKGNAMEPREFIX=	py-
DISTFILES=

MAINTAINER=	jdugan@x1024.net
COMMENT=	Python interface to Thrift

BROKEN=		needs updating for Apache Incubator version

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/py ${WRKSRC}

.include <bsd.port.mk>
