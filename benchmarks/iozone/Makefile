# New ports collection makefile for:    iozone
# Version required:     2.01
# Date created:         26 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.13 1995/06/15 11:26:50 jmz Exp $
#

DISTNAME=       iozone
PKGNAME=	iozone-2.01
CATEGORIES+=	benchmarking
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
DISTFILES=      iozone-2.01.shar.gz

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_CMD=    ( gzcat | awk '{if (/^\#!/) x++} {if(x) print $$0'}| /bin/sh )
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES

.include <bsd.port.mk>
