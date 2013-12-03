# Created by: Alexander Botero-Lowry <alexbl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magic
PORTVERSION=	5.16
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.gw.com/mirrors/pub/unix/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	file-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python module for determining file type

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Magic_file_extensions
PYDISTUTILS_PKGVERSION=	0.2

WRKSRC=	${WRKDIR}/file-${PORTVERSION}/python

.include <bsd.port.mk>
