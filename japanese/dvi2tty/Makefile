# New ports collection makefile for:	dvi2tty
# Version required:		5.0
# Date created:			30 Mar. 1996
# Whom:				Masafumi NAKANE <max@sfc.wide.ad.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/04/26 08:29:48 asami Exp $
#

DISTNAME=	dvi2tty5.0
PKGNAME=	jp-dvi2tty-ascii-5.0
CATEGORIES+=	japanese print
MASTER_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/misc/tex/dviwares/dvi2tty/ \
		ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/

PATCH_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/misc/tex/dviwares/dvi2tty/ \
		ftp://ftp.web.ad.jp/pub/TeX/akiu/dviwares/dvi2tty/
PATCHFILES=	dvi2tty-ascii-jtex-patch dvi2tty.c-patch

MAINTAINER=	max@sfc.wide.ad.jp

RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less
PATCH_DIST_STRIP=	-p1

do-install:
	(for f in jdvi2tty disdvi ; do ; \
	${INSTALL} -m 755 -o bin -g bin -cs ${WRKSRC}/$$f ${PREFIX}/bin ; done)
	${INSTALL} -m 644 -o bin -g bin -c ${WRKSRC}/dvi2tty.1 ${PREFIX}/man/man1
	-ln -sf ${PREFIX}/bin/jdvi2tty ${PREFIX}/bin/dvi2tty
.if !defined(NOMANCOMPRESS)
	@gzip -9f ${PREFIX}/man/man1/dvi2tty.1
	@ln -sf ${PREFIX}/man/man1/dvi2tty.1.gz ${PREFIX}/man/man1/jdvi2tty.1.gz
.else
	@ln -sf ${PREFIX}/man/man1/dvi2tty.1 ${PREFIX}/man/man1/jdvi2tty.1
.endif

.include <bsd.port.mk>
