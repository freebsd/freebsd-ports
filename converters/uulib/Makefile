# New ports collection makefile for:	uulib
# Version Required:     0.5.9
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.14 1998/02/18 22:20:02 hoek Exp $
#

DISTNAME=       uudeview-0.5.13
PKGNAME=        uulib-0.5.13
CATEGORIES=	converters
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/ \
		http://www.informatik.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	hoek@FreeBSD.ORG

GNU_CONFIGURE=		yes

MAN3=		uulib.3

ALL_TARGET=	libuu.a	libuu.so.1.0

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/uulib/libuu.so.1.0 ${PREFIX}/lib
	@${LDCONFIG} -m ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/uulib/libuu.a ${PREFIX}/lib
	@/usr/bin/ranlib ${PREFIX}/lib/libuu.a
	${INSTALL_DATA} ${WRKSRC}/uulib/uudeview.h ${PREFIX}/include/uu.h
	${INSTALL_MAN} ${FILESDIR}/uulib.3 ${PREFIX}/man/man3
	perl -pi -e '$$a = '\''${PREFIX}/'\''; $$a =~ s/([^\w\/])/\\$$1/g; s/FUNKYTOKENHERE/$$a/' ${PREFIX}/man/man3/uulib.3
.if !defined(NOPORTDOCS)
	@echo "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${PREFIX}/share/doc/uulib
	@${INSTALL_MAN} ${FILESDIR}/porting.notes ${PREFIX}/share/doc/uulib
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/uulib
.endfor
.endif

.include <bsd.port.mk>
