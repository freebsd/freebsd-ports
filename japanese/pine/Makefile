# New ports collection makefile for:	jp-pine
# Version required:	3.91
# Date created:		14 Apr 1996
# Whom:			masafumi
#
# $Id: Makefile,v 1.11 1995/08/14 11:52:36 asami Exp $
#

DISTNAME=	pine3.91
PKGNAME=	jp-pine-3.91
CATEGORIES+=	japanese mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/pine/
DISTFILES=	pine3.91.tar.Z pine3.91j1.0.tar.gz

PATCHFILES=	pine3.91j1.0-1.0.1.gz pine3.91j1.0.1-1.0.2.gz
PATCH_SITES=	ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/pine/

MAINTAINER=	max@sfc.wide.ad.jp

EXTRACT_ONLY=	pine3.91.tar.Z

pre-patch:
	@(cd ${WRKSRC}; \
	  tar zxf ${DISTDIR}/pine3.91j1.0.tar.gz; \
	  patch -s -p1 <pine3.91j1.0.diff)

.if defined(BATCH)
do-configure:
	@(if [ ! -f ${WRKSRC}/pine/pine-e.hlp ]; then; \
	    mv ${WRKSRC}/pine/pine.hlp ${WRKSRC}/pine/pine-e.hlp ; \
	  fi)
	@ln -fs ${WRKSRC}/pine/pine-j.hlp ${WRKSRC}/pine/pine.hlp
.endif

BUILD_DEPENDS=	${PREFIX}/lib/libmimekit.a:${PORTSDIR}/japanese/mimekit

do-build:
	(cd ${WRKSRC}; ./build bsf)

do-install:
	install -cs -o bin -g bin ${WRKSRC}/bin/imapd ${PREFIX}/libexec/imapd
	install -cs -o bin -g bin ${WRKSRC}/imap/systype/ipopd/ipop2d ${PREFIX}/libexec/ipop2d
	install -cs -o bin -g bin ${WRKSRC}/imap/systype/ipopd/ipop3d ${PREFIX}/libexec/ipop3d
	install -cs -o bin -g bin ${WRKSRC}/bin/mtest ${PREFIX}/bin/mtest
	install -cs -o bin -g bin ${WRKSRC}/bin/pico ${PREFIX}/bin/pico
	install -cs -o bin -g bin ${WRKSRC}/bin/pine ${PREFIX}/bin/pine
	install -c -o bin -g bin ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/pico.1
	install -c -o bin -g bin ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
	install -c -o bin -g bin ${WRKSRC}/imap/systype/imapd/imapd.8c ${PREFIX}/man/man8/imapd.8c
	install -c -o bin -g bin ${WRKSRC}/imap/systype/ipopd/ipopd.8c ${PREFIX}/man/man8/ipopd.8c

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/pine.1
	gzip -9nf ${PREFIX}/man/man1/pico.1
	gzip -9nf ${PREFIX}/man/man8/imapd.8c
	gzip -9nf ${PREFIX}/man/man8/ipopd.8c
.endif

.include <bsd.port.mk>
