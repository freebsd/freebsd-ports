# New ports collection makefile for:    elk
# Version required:     3.0
# Date created:         08 March 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.8 1995/11/22 13:12:36 asami Exp $
#

DISTNAME=       elk-3.0
CATEGORIES+=	lang
KEYWORDS+=	lang scheme
MASTER_SITES=	ftp://ftp.uni-bremen.de/pub/programming/languages/scheme/elk/ \
		ftp://crl.dec.com/pub/X11/contrib/devel_tools/ \
		ftp://ftp.th-darmstadt.de/pub/X11/contrib/devel_tools/

PATCHFILES=	elk-3.0-patch-1
PATCH_SITES=	ftp://ftp.uni-bremen.de/pub/programming/languages/scheme/elk/

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

PATCH_STRIP=	-p1
ALL_TARGET=	default

#
# /usr/local/lib/elk is built into the port.
# change it in ${WRKSRC}/config/site if you change it here and vice versa.
# i also renamed /usr/local/bin/scheme to /usr/local/bin/elk
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
