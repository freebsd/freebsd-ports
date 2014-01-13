# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	imgtops
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create efficient Encapsulated Postscript files from images

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

MAN1=		imgtops.1 epstoimg.1

NO_STAGE=	yes
post-install:
	${CHMOD} 644 ${MANPREFIX}/man/man1/imgtops.1
	${CHMOD} 644 ${MANPREFIX}/man/man1/epstoimg.1

.include <bsd.port.mk>
