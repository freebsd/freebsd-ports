# New ports collection makefile for:    zip (without encryption)
# Version required:     2.2
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       zip22
PKGNAME=        zip-2.2
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/src/

MAINTAINER=     ache@FreeBSD.org

Y2K=		http://www.cdrom.com/pub/infozip/FAQ.html#Y2K

WRKSRC=         ${WRKDIR}/zip-2.2
MAKEFILE=       unix/Makefile
MAKE_FLAGS=     LOCAL_ZIP="${CFLAGS}" -f
ALL_TARGET=     generic
MAN1=           zip.1

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
