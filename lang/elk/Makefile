# New ports collection makefile for:    elk
# Version required:     2.2
# Date created:         08 March 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id$
#

DISTNAME=       elk-2.2
CATEGORIES+=	languages
MASTER_SITES=	ftp://ftp.x.org/contrib/devel_tools/

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
	@mkdir -p ${PREFIX}/lib/elk

post-install:
	@(cd ${PREFIX}/lib/elk; \
	  mv bin/scheme ${PREFIX}/bin/elk; \
	  mkdir -p ${PREFIX}/include/elk; \
	  mv include/*.h ${PREFIX}/include/elk; \
	  rmdir bin include)
	@install -c -o bin -g bin -m 444 ${WRKSRC}/doc/man/elk.1 ${PREFIX}/man/man1
	@gzip -9nf ${PREFIX}/man/man1/elk.1

.include <bsd.port.mk>
