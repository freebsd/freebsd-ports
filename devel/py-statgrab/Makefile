# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	statgrab
PORTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/libstatgrab/pystatgrab/releases/download/PYSTATGRAB_${PORTVERSION:S/./_/g}/ \
		http://ftp.mirrorservice.org/pub/i-scream/py${PORTNAME}/ \
		http://ftp.i-scream.org/pub/i-scream/py${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Set of Python bindings for libstatgrab

LICENSE=	LGPL21

LIB_DEPENDS=	libstatgrab.so:devel/libstatgrab

USES=		pkgconfig python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
