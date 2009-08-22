# New ports collection makefile for:	py-fam
# Date created:		8 October 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	fam
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	SF/python-${PORTNAME}/python-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-fam-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Interface to the File Alteration Monitor

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_fam.so
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.0.0
USE_FAM=	yes

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
