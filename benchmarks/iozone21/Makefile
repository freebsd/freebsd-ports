# New ports collection makefile for:    iozone
# Version required:     2.01
# Date created:         26 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.12 1995/04/23 13:02:24 asami Exp $
#

DISTNAME=       iozone
PKGNAME=	iozone-2.01
CATEGORIES+=	utilities
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
DISTFILES=      iozone-2.01.shar.gz

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_CMD=    ( gzcat | awk '{if (/^\#!/) x++} {if(x) print $$0'}| /bin/sh )
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES

.include <bsd.port.mk>
