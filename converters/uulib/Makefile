# New ports collection makefile for:	uulib
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	uulib
PORTVERSION=	0.5.13
CATEGORIES=	converters
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/ \
		http://www.informatik.uni-frankfurt.de/~fp/uudeview/Apps/frank/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	hoek@FreeBSD.org

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		uulib.3

ALL_TARGET=	libuu.a	libuu.so.${VERSION}

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
VERSION=	1
.else
VERSION=	1.0
.endif

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/uulib/libuu.so.${VERSION} ${PREFIX}/lib
	${LN} -sf libuu.so.${VERSION} ${PREFIX}/lib/libuu.so
	${INSTALL_DATA} ${WRKSRC}/uulib/libuu.a ${PREFIX}/lib
	@/usr/bin/ranlib ${PREFIX}/lib/libuu.a
	${INSTALL_DATA} ${WRKSRC}/uulib/uudeview.h ${PREFIX}/include
	${INSTALL_MAN} ${FILESDIR}/uulib.3 ${PREFIX}/man/man3
	perl -pi -e '$$a = '\''${PREFIX}/'\''; $$a =~ s/([^\w\/])/\\$$1/g; s/FUNKYTOKENHERE/$$a/' ${PREFIX}/man/man3/uulib.3
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${PREFIX}/share/doc/uulib
	@${INSTALL_MAN} ${FILESDIR}/porting.notes ${PREFIX}/share/doc/uulib
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/uulib
.endfor
.endif

.include <bsd.port.post.mk>
