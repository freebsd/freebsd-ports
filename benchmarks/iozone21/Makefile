# New ports collection makefile for:    iozone
# Version required:     2.01
# Date created:         26 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.18 1996/11/18 13:57:01 asami Exp $
#

DISTNAME=       iozone-2.01
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
EXTRACT_SUFX=	.shar.gz

# This site does not allow root@<hostname> password
FETCH_CMD=      FTP_PASSWORD=portsuser@FreeBSD.org /usr/bin/fetch

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_CMD=    ( gzcat | awk '{if (/^\#!/) x++} {if(x) print $$0'}| /bin/sh )
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES
MAN1=		iozone.1

.include <bsd.port.mk>
