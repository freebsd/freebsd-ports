# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	1.5.0
CATEGORIES=	devel
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/34574/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	CVS to Subversion Repository Converter

FETCH_DEPENDS=	wget:${PORTSDIR}/ftp/wget
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm
RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		${BUILD_DEPENDS}

FETCH_CMD?=	wget -c

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

MAN1=		cvs2svn.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/cvs2svn.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
