# New ports collection makefile for:	mule
# Version required:	2.3
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.21 1995/07/23 22:32:38 asami Exp $
#

DISTNAME=	mule-2.3
CATEGORIES+=	editors
MASTER_SITES=	ftp://ftp.cs.buffalo.edu/pub/mule/ \
		ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/ \
		ftp://ftp.funet.fi/pub/gnu/emacs/mule/

MAINTAINER=	asami@FreeBSD.ORG

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} --with-x-toolkit \
		--terminal-face \
		--locallisppath=${PREFIX}/lib/mule/site-lisp:${PREFIX}/share/emacs/site-lisp
STRIP=

pre-build:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;

post-install:
# note that any2ps is a script
	strip ${PREFIX}/bin/b2m
	strip ${PREFIX}/bin/coco
	strip ${PREFIX}/bin/m2ps
	strip ${PREFIX}/bin/mule-19.28
	gzip -9nf ${PREFIX}/man/man1/coco.1
	gzip -9nf ${PREFIX}/man/man1/m2ps.1
	gzip -9nf ${PREFIX}/man/man1/mule.1

.include <bsd.port.mk>
