# New ports collection makefile for:	zodb3
# Date created:		8 Dezember 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	zodb3
PORTVERSION=	3.1
CATEGORIES=	databases
MASTER_SITES=	http://www.zope.org/Products/ZODB3.1/
DISTNAME=	ZODB3-${PORTVERSION}

MAINTAINER=	ports@freebsd.org
COMMENT=	The Z - Object Database for python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@ ${SH} ${PKGREQ} INSTALL

eNU_CONFIGURE=	yes

.include <bsd.port.mk>
