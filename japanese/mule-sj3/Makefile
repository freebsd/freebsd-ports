# New ports collection makefile for:	mule with sj3
# Version required:	2.3
# Date created:		8 August 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/08/19 11:56:49 asami Exp $
#

DISTNAME=	mule-2.3
PKGNAME=	jp-smule-2.3
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/ \
		ftp://ftp.funet.fi/pub/gnu/emacs/mule/

MAINTAINER=	hidekazu@cs.titech.ac.jp

BUILD_DEPENDS=	sj3serv:${PORTSDIR}/japanese/sj3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit \
		--sj3 --terminal-face \
		--locallisppath=${PREFIX}/lib/mule/site-lisp:${PREFIX}/share/emacs/site-lisp
STRIP=

pre-build:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;

post-install:
# note that rcs-checkn and any2ps are scripts
	strip ${PREFIX}/bin/b2m
	strip ${PREFIX}/bin/coco
	strip ${PREFIX}/bin/ctags
	strip ${PREFIX}/bin/etags
	strip ${PREFIX}/bin/m2ps
	strip ${PREFIX}/bin/mule-19.28
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/coco.1
	gzip -9nf ${PREFIX}/man/man1/ctags.1
	gzip -9nf ${PREFIX}/man/man1/etags.1
	gzip -9nf ${PREFIX}/man/man1/m2ps.1
	gzip -9nf ${PREFIX}/man/man1/mule.1
.endif

.include <bsd.port.mk>
