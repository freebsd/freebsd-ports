# New ports collection makefile for:	uulib
# Version Required:	0.5.4 (aka. 0.5pl4)
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.3 1996/11/18 11:23:49 asami Exp $
#

DISTNAME=	uudeview-0.5.4
PKGNAME=	uulib-0.5.4
CATEGORIES=	devel
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	ac199@freenet.hamilton.on.ca

GNU_CONFIGURE=	yes
ALL_TARGET=	libuu.a
MAN3=		uulib.3

EXTRAFILES+=	uulib.3
EXTRAFILES+=	porting.notes

DOCFILES+=	doc/Makefile
DOCFILES+=	doc/README
DOCFILES+=	doc/binhex.fig
DOCFILES+=	doc/library.ltx
DOCFILES+=	doc/structure.fig
DOCFILES+=	doc/td-v1.c
DOCFILES+=	doc/td-v2.c
DOCFILES+=	doc/td-v3.c
DOCFILES+=	doc/test.txt
DOCFILES+=	porting.notes

post-patch:
	@for l in ${EXTRAFILES}; \
	do \
		cp ${FILESDIR}/$${l} ${WRKSRC}/$${l}; \
	done

do-install:
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/share/doc/uulib
	for l in ${DOCFILES}; \
	do \
		cp ${WRKSRC}/$$l ${PREFIX}/share/doc/uulib; \
	done
.endif
	cp ${WRKSRC}/uulib.3 ${PREFIX}/man/man3/uulib.3
	perl -pi -e '$$a = '\''${PREFIX}/'\''; $$a =~ s/([^\w\/])/\\$$1/g; s/FUNKYTOKENHERE/$$a/' ${PREFIX}/man/man3/uulib.3
	cp ${WRKSRC}/uulib/libuu.a ${PREFIX}/lib/libuu.a
	cp ${WRKSRC}/uulib/uudeview.h ${PREFIX}/include/uu.h

.include <bsd.port.mk>
