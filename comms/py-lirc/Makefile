# New ports collection makefile for:	py23-lirc
# Date created:		6 January 2004
# Whom:			Lewis Thompson (purple@lewiz.net)
#
# $FreeBSD$
#

PORTNAME=	lirc
PORTVERSION=	0.0.5
PORTREVISION=	3
CATEGORIES=	comms python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylirc-${PORTVERSION}

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Lirc support library for Python

LIB_DEPENDS=	lirc_client.2:${PORTSDIR}/comms/lirc

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	LDFLAGS="${LDFLAGS}"
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pylircmodule.so

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pylirc

.include <bsd.port.mk>
