# New ports collection makefile for:	mule with Canna
# Version required:	2.2.2
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.20 1995/07/20 00:25:21 asami Exp $
#

DISTNAME=	mule-2.2
PKGNAME=	jp-cmule-2.2.2
CATEGORIES+=	japanese editors
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/

PATCH_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/
PATCHFILES=	patch-2.2.1.gz patch-2.2.2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=        i386--freebsd --prefix=${PREFIX} --with-x-toolkit \
		--canna --canna-libraries=/usr/local/lib \
		--canna-includes=/usr/local/canna/include --terminal-face \
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
