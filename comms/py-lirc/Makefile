# New ports collection makefile for:	py23-lirc
# Date created:		6 January 2004
# Whom:			Lewis Thompson (purple@lewiz.net)
#
# $FreeBSD$
#

PORTNAME=	lirc
PORTVERSION=	0.0.4
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylirc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylirc-${PORTVERSION}

MAINTAINER=	purple@lewiz.net
COMMENT=	Lirc support library for Python

LIB_DEPENDS=	lirc_client.0:${PORTSDIR}/comms/lirc

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pylircmodule.so

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.mk>
