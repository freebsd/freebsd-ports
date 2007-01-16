# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	1.5.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rewt.org.uk/pub/distfiles/ \
		http://gentoo.nedlinux.nl/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	CVS to Subversion Repository Converter

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm
RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
		${BUILD_DEPENDS}

DISABLE_SIZE=	yes

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

MAN1=		cvs2svn.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/cvs2svn.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
