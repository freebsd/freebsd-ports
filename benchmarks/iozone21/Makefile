# New ports collection makefile for:    iozone
# Version required:     2.01
# Date created:         26 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.17 1996/11/18 11:21:53 asami Exp $
#

DISTNAME=       iozone
PKGNAME=	iozone-2.01
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
DISTFILES=      iozone-2.01.shar.gz

# This site not allows root@<hostname> password
FETCH_CMD=      FTP_PASSWORD=president@whitehouse.gov /usr/bin/fetch

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_CMD=    ( gzcat | awk '{if (/^\#!/) x++} {if(x) print $$0'}| /bin/sh )
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES
MAN1=		iozone.1

.include <bsd.port.mk>
