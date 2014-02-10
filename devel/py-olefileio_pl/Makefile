# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	olefileio_pl
PORTVERSION=	0.30
CATEGORIES=	devel python
MASTER_SITES=	http://cdn.bitbucket.org/decalage/olefileio_pl/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OleFileIO_PL-${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python module to read MS OLE2 files

LICENSE=	MIT

USES=		dos2unix
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} "s|, 'OleFileIO_PL2'||" ${WRKSRC}/setup.py

.include <bsd.port.mk>
