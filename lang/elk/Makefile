# New ports collection makefile for:    elk
# Version required:     3.0pl2
# Date created:         08 March 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.10 1996/03/06 08:20:07 asami Exp $
#

DISTNAME=	elk-3.0
PKGNAME=	elk-3.0.2
CATEGORIES+=	lang
MASTER_SITES=	ftp://ftp.uni-bremen.de/pub/programming/languages/scheme/elk/ \
		ftp://crl.dec.com/pub/X11/contrib/devel_tools/ \
		ftp://ftp.th-darmstadt.de/pub/X11/contrib/devel_tools/

MAINTAINER=	tg@freebsd.org

PATCH_STRIP=	-p1
ALL_TARGET=	default

#
# we install the scheme binary as ${PREFIX}/bin/elk
# to avoid a clash with mit-scheme.
#

pre-install:
	@mkdir -p ${PREFIX}/share/elk

post-install:
	@(cd ${PREFIX}/share/elk; \
	  cp bin/scheme ${PREFIX}/bin/elk; \
	  mkdir -p ${PREFIX}/include/elk; \
	  cp -R include/* ${PREFIX}/include/elk; \
	  rm -rf bin include)
	@install -c -o bin -g bin -m 444 ${WRKSRC}/doc/man/elk.1 ${PREFIX}/man/man1
.if !defined(NOMANCOMPRESS)
	@gzip -9nf ${PREFIX}/man/man1/elk.1
.endif

.include <bsd.port.mk>
