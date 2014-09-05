# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	olefileio_pl
PORTVERSION=	0.31
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OleFileIO_PL-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python module to read MS OLE2 files

LICENSE=	MIT

USES=		dos2unix python zip
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} "/^if sys\.version_info/,/OleFileIO_PL2/d" ${WRKSRC}/setup.py

.include <bsd.port.mk>
