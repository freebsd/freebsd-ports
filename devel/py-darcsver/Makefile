# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	darcsver
PORTVERSION=	1.7.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generate a version number from darcs history

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#(doc_loc, data_fnames)##g' ${WRKSRC}/setup.py


.include <bsd.port.mk>
