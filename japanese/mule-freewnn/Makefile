# New ports collection makefile for:	mule with Wnn
# Version required:	2.3
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.22 1995/07/28 23:46:43 asami Exp $
#

DISTNAME=	mule-2.3
PKGNAME=	jp-wmule-2.3
CATEGORIES+=	japanese editors
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/ \
		ftp://ftp.funet.fi/pub/gnu/emacs/mule/

MAINTAINER=	asami@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} --with-x-toolkit \
		--with-wnn4 --wnn-libraries=/usr/X11R6/lib \
		--wnn-includes=/usr/X11R6/include/wnn --terminal-face \
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
	gzip -9nf ${PREFIX}/man/man1/coco.1
	gzip -9nf ${PREFIX}/man/man1/ctags.1
	gzip -9nf ${PREFIX}/man/man1/etags.1
	gzip -9nf ${PREFIX}/man/man1/m2ps.1
	gzip -9nf ${PREFIX}/man/man1/mule.1

.include <bsd.port.mk>
