# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/20727/

MAINTAINER=	jihuang@gate.sinica.edu.tw
COMMENT=	CVS to Subversion Repository Converter

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
