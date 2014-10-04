# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	imgtops
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create efficient Encapsulated Postscript files from images

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow

USES=			python
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=		distutils

post-install:
	${CHMOD} 644 ${STAGEDIR}${MANPREFIX}/man/man1/imgtops.1
	${CHMOD} 644 ${STAGEDIR}${MANPREFIX}/man/man1/epstoimg.1

.include <bsd.port.mk>
