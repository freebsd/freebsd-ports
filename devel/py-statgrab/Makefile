# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	statgrab
PORTVERSION=	0.5
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://ftp.uk.i-scream.org/pub/i-scream/%SUBDIR%/ \
		ftp://ftp.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://ftp.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A set of Python bindings for libstatgrab

LIB_DEPENDS=	statgrab.8:${PORTSDIR}/devel/libstatgrab

DIST_SUBDIR=	i-scream
USES=		pkgconfig
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pystatgrab

NO_STAGE=	yes
.include <bsd.port.mk>
