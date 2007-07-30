# New ports collection makefile for:	py-fusefs
# Date created:		22 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fusefs
DISTVERSION=	0.2pre1-20060720
CATEGORIES=	devel
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fuse-python-${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	FUSE Python bindings

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	pkgconfig

PYDISTUTILS_PKGNAME=	fuse-python
PYDISTUTILS_PKGVERSION=	0.2pre1

.include <bsd.port.mk>
