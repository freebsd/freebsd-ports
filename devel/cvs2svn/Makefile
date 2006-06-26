# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rewt.org.uk/pub/distfiles/ \
		http://mirror.crystal-vps.co.uk/distfiles/

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	CVS to Subversion Repository Converter

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
