# New ports collection makefile for:    unzip.with_encryption
# http://infozip.cdrom.com/pub/infozip/
#
# Version required:     5.3
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.22 1997/01/06 21:40:46 ache Exp $
#

DISTNAME=       unzip53
PKGNAME=        unzip+crypt-5.3
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.icce.rug.nl/infozip/OLD/beta/
DISTFILES=      unzip53.zip zcrypt27.zip

MAINTAINER=     ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	"This program can't be imported/re-exported from USA"
EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -oq
NO_WRKSUBDIR=   yes
MAKEFILE=       unix/Makefile
ALL_TARGET=     bsd
MAKE_FLAGS=     LOCAL_UNZIP="${CFLAGS} -DUSE_SMITH_CODE -DUSE_UNSHRINK" -f
MAN1=           funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	ln -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && \
		${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/unix && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
