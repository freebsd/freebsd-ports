# New ports collection makefile for:	py-fam
# Date created:		8 October 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	fam
PORTVERSION=	1.0.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= python-fam
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-fam-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Interface to the File Alteration Monitor

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_fam.so
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/setup.py ${WRKSRC}

.include <bsd.port.mk>
