# New ports collection makefile for:    unzip
# Version required:     5.*
# Date created:         17 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.21 1998/10/05 03:41:16 jkh Exp $
#

DISTNAME=       unzip540
PKGNAME=        unzip-5.40
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/src/

MAINTAINER=     ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/unzip-5.40
MAKEFILE=       unix/Makefile
MAKE_FLAGS=     LOCAL_UNZIP="${CFLAGS} -DUSE_UNSHRINK" -f
MAN1=           funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	ln -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && \
		${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/unix && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	${INSTALL} -d -m 555 -o ${SHAREOWN} -g ${SHAREGRP} ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && \
		${INSTALL_DATA} README COPYING WHERE ${PREFIX}/share/doc/unzip

.include <bsd.port.mk>

.if ${ARCH} == "alpha"
ALL_TARGET=	bsd
.else
ALL_TARGET=     freebsd
.endif
