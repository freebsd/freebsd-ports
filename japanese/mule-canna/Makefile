# New ports collection makefile for:	mule with Canna
# Version required:	2.3
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.25 1996/11/11 10:12:30 max Exp $
#

DISTNAME=	mule-2.3
PKGNAME=	jp-cmule-2.3
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.cs.buffalo.edu/pub/mule/ \
		ftp://sh.wide.ad.jp/JAPAN/mule/ \
		ftp://ftp.funet.fi/pub/gnu/emacs/mule/

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=        i386--freebsd --with-x-toolkit \
		--canna --canna-libraries=/usr/local/lib \
		--canna-includes=/usr/local/include --terminal-face \
		--locallisppath=${PREFIX}/lib/mule/site-lisp:${PREFIX}/share/emacs/site-lisp
STRIP=
MAN1=		coco.1 ctags.1 etags.1 m2ps.1 mule.1

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

.include <bsd.port.mk>
