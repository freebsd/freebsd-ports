# New ports collection makefile for:	jp-pine
# Version required:	3.95lj1.1b3
# Date created:		01 May 1996
# Whom:			masafumi
#
# $Id: Makefile,v 1.11 1995/08/14 11:52:36 asami Exp $
#

DISTNAME=	pine3.95
PKGNAME=	jp-pine-3.95
CATEGORIES+=	japanese mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/pine/pine3.95/
DISTFILES=	pine3.95.tar.gz pine3.95lj1.1b2.tar.gz
PATCHFILES=	pine3.95lj1.1b2-b3.diff.gz
PATCH_SITES=	ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/pine/pine3.95/
MAINTAINER=	max@FreeBSD.ORG

EXTRACT_ONLY=	pine3.95.tar.gz

pre-patch:
	@(cd ${WRKSRC}; \
	  tar zxf ${DISTDIR}/pine3.95lj1.1b2.tar.gz; \
	  patch -s -p0 < japan/pine3.95lj1.1b2.diff)

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	${PREFIX}/lib/libcanna.a:${PORTSDIR}/japanese/Canna

do-build:
	(cd ${WRKSRC}; ./build bsf)

do-install:
	install -cs -o bin -g bin ${WRKSRC}/bin/imapd ${PREFIX}/libexec
	install -cs -o bin -g bin ${WRKSRC}/bin/ipop2d ${PREFIX}/libexec
	install -cs -o bin -g bin ${WRKSRC}/bin/ipop3d ${PREFIX}/libexec
	install -cs -o bin -g bin ${WRKSRC}/bin/mtest ${PREFIX}/bin
	install -cs -o bin -g bin ${WRKSRC}/bin/pico ${PREFIX}/bin
	install -cs -o bin -g bin ${WRKSRC}/bin/pilot ${PREFIX}/bin
	install -cs -o bin -g bin ${WRKSRC}/bin/pine ${PREFIX}/bin
	install -cs -o bin -g bin ${WRKSRC}/bin/libc-client.so.1.3 $(PREFIX)/lib
	install -cs -o bin -g bin ${WRKSRC}/bin/libpico.so.1.3 $(PREFIX)/lib
	install -c -o bin -g bin ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1
	install -c -o bin -g bin ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1
	install -c -o bin -g bin ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1
	@(if [ ! -d ${PREFIX}/lib/pine ]; then; \
	     /bin/mkdir -p ${PREFIX}/lib/pine ;\
	 fi)
	install -c -o bin -g bin ${WRKSRC}/pine/pine.hlp ${PREFIX}/lib/pine
	install -c -o bin -g bin ${WRKSRC}/pine/pine.ndx ${PREFIX}/lib/pine
	install -c -o bin -g bin ${WRKSRC}/pine/pine_ja.hlp ${PREFIX}/lib/pine
	install -c -o bin -g bin ${WRKSRC}/pine/pine_ja.ndx ${PREFIX}/lib/pine
	install -c -o bin -g bin ${WRKSRC}/imap/systype/imapd/imapd.8c ${PREFIX}/man/man8
	install -c -o bin -g bin ${WRKSRC}/imap/systype/ipopd/ipopd.8c ${PREFIX}/man/man8
	ldconfig -vm /usr/local/lib

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/pine.1
	gzip -9nf ${PREFIX}/man/man1/pilot.1
	gzip -9nf ${PREFIX}/man/man1/pico.1
	gzip -9nf ${PREFIX}/man/man8/imapd.8c
	gzip -9nf ${PREFIX}/man/man8/ipopd.8c
.endif

.include <bsd.port.mk>
