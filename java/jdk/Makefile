# New ports collection makefile for:	jdk
# Version required:     1.0.1
# Date created:		8 April 1996
# Whom:			Sujal Patel <smpatel@umiacs.umd.edu>
#
# $Id: Makefile,v 1.1.1.1 1996/04/01 04:02:45 asami Exp $
#

DISTNAME=       jdk
PKGNAME=	jdk-1.0.1
CATEGORIES+=	www devel
MASTER_SITES=   ftp://ftp.javasoft.com/pub/ \
		ftp://www.blackdown.org/pub/Java/pub/
DISTFILES=      JDK-1_0_1-solaris2-sparc.tar.Z

MAINTAINER=	smpatel@umiacs.umd.edu

NO_WRKSUBDIR=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
