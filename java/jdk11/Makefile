# New ports collection makefile for:	jdk
# Version required:     1.0.2
# Date created:		8 April 1996
# Whom:			Sujal Patel <smpatel@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1996/04/08 20:49:12 smpatel Exp $
#

DISTNAME=       jdk
PKGNAME=	jdk-1.0.2
CATEGORIES+=	www devel
MASTER_SITES=   ftp://ftp.javasoft.com/pub/ \
		ftp://www.blackdown.org/pub/Java/pub/
DISTFILES=      JDK-1_0_2-solaris2-sparc.tar.Z

MAINTAINER=	smpatel@freebsd.org

NO_WRKSUBDIR=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
