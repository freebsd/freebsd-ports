# New ports collection makefile for:	jp-pine
# Version required:	3.95lj1.1b3
# Date created:		01 May 1996
# Whom:			masafumi
#
# $Id: Makefile,v 1.11 1997/07/17 15:12:46 max Exp $
#

DISTNAME=	pine3.95
PKGNAME=	ja-pine-3.95
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/pine/pine3.95/
DISTFILES=	pine3.95.tar.gz pine3.95lj1.1b2.tar.gz

PATCHFILES=	pine3.95lj1.1b2-b3.diff.gz
PATCH_SITES=	ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/pine/pine3.95/

MAINTAINER=	max@FreeBSD.ORG

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	${PREFIX}/lib/libcanna.a:${PORTSDIR}/japanese/Canna

EXTRACT_ONLY=	pine3.95.tar.gz
MAN1=		pine.1 pilot.1 pico.1

pre-patch:
	@(cd ${WRKSRC}; \
	  tar zxf ${DISTDIR}/pine3.95lj1.1b2.tar.gz; \
	  patch -s -p0 < japan/pine3.95lj1.1b2.diff)

do-build:
	(cd ${WRKSRC}; ./build bsf)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/libpico.so.1.3 $(PREFIX)/lib
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine.hlp ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine.ndx ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine_ja.hlp ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine_ja.ndx ${PREFIX}/lib/pine
	${LDCONFIG} -m /usr/local/lib

.include <bsd.port.mk>
