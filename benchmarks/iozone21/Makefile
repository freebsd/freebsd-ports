# New ports collection makefile for:    iozone
# Version required:     2.01
# Date created:         26 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.11 1995/04/15 03:45:40 asami Exp $
#

DISTNAME=       iozone
PKGNAME=	iozone-2.01
CATEGORIES+=	utilities
MASTER_SITES=   ftp://ftp.cs.uni-sb.de/pub/others/
DISTFILES=      iozone-2.01.shar.gz

MAINTAINER=	jmz@FreeBSD.org

EXEC_DEPENDS=   gunshar:${PORTSDIR}/archivers/gshar+gunshar

EXTRACT_CMD=    ( gzcat | /usr/local/bin/gunshar )
EXTRACT_ARGS=   <
NO_WRKSUBDIR=   YES

.include <bsd.port.mk>
