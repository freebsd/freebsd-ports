# New ports collection makefile for:	py-statgrab
# Date created:		20 March 2004
# Whom:			Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	statgrab
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.mirrorservice.org/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		ftp://ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://www.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	tim@bishnet.net
COMMENT=	A set of Python bindings for libstatgrab

LIB_DEPENDS=	statgrab.6:${PORTSDIR}/devel/libstatgrab

DIST_SUBDIR=	i-scream
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
