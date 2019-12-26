# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	freebsd
PORTVERSION=	0.9.3
PORTREVISION=	8
CATEGORIES=	devel python
MASTER_SITES=	LOCAL/perky \
		http://people.freebsd.org/~perky/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-freebsd-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FreeBSD-specific system libraries

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/freebsd.so

.include <bsd.port.mk>
