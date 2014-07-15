# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	statgrab
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.uk.i-scream.org/pub/i-scream/%SUBDIR%/ \
		http://ftp.i-scream.org/pub/i-scream/%SUBDIR%/
MASTER_SITE_SUBDIR=	py${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Set of Python bindings for libstatgrab

LIB_DEPENDS=	libstatgrab.so:${PORTSDIR}/devel/libstatgrab

USES=		pkgconfig
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
