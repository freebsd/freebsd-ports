# New ports collection makefile for:	jdk
# Version required:     1.0.2
# Date created:		8 April 1996
# Whom:			Sujal Patel <smpatel@freebsd.org>
#
# $Id: Makefile,v 1.2 1996/06/16 04:34:18 smpatel Exp $
#

DISTNAME=       jdk
PKGNAME=	jdk-1.0.2
CATEGORIES+=	www devel
MASTER_SITES=   ftp://ftp.javasoft.com/pub/ \
		ftp://www.blackdown.org/pub/Java/pub/
DISTFILES=      JDK-1_0_2-solaris2-sparc.tar.Z

MAINTAINER=	smpatel@freebsd.org

NO_WRKSUBDIR=	yes
NO_CDROM=	yes	# put copyright on packaging etc.

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
