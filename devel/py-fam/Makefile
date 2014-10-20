# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	fam
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	SF/python-${PORTNAME}/python-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-fam-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to the File Alteration Monitor

USES=		python fam
USE_PYTHON=	distutils autoplist

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
