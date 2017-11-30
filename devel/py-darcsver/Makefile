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

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's#(doc_loc, data_fnames)##g' ${WRKSRC}/setup.py


.include <bsd.port.mk>
