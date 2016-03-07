# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	olefile
PORTVERSION=	0.43
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python module to read MS OLE2 files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/olefile/LICENSE.txt

NO_ARCH=	yes
USES=		dos2unix python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

# Remove files not python 3 ready and allow compile again
post-patch:
.if ${PYTHON_REL} >= 3000
	${RM} ${WRKSRC}/olefile/olefile2.py
.endif
	${REINPLACE_CMD} "/install' in sys.argv:/,+1d" ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
