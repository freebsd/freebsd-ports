# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/25036/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	CVS to Subversion Repository Converter

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
