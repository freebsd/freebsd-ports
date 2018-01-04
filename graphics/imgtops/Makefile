# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	imgtops
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create efficient Encapsulated Postscript files from images

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR}

USES=			ghostscript:run python:2.7
USE_PYTHON=		distutils

post-install:
	${CHMOD} 644 ${STAGEDIR}${MANPREFIX}/man/man1/imgtops.1
	${CHMOD} 644 ${STAGEDIR}${MANPREFIX}/man/man1/epstoimg.1
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/imgtopslib/encoders.so

.include <bsd.port.mk>
