# New ports collection makefile for:	uulib
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	uulib
PORTVERSION=	0.5.20
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for uu/xx/Base64/BinHex/yEnc de-/encoding

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
ALL_TARGET=	libuu.a	libuu.so.${SHLIB_VER}
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN3=		uulib.3
PORTDOCS=	*
PLIST_FILES=	include/uudeview.h lib/libuu.a lib/libuu.so \
		lib/libuu.so.${SHLIB_VER}

SHLIB_VER=	3

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

post-patch:
	@${SED} -e 's,FUNKYTOKENHERE,${PREFIX}/,' \
		< ${FILESDIR}/uulib.3 > ${WRKDIR}/uulib.3

do-install:
	${INSTALL_DATA} ${WRKSRC}/uulib/libuu.so.${SHLIB_VER} ${PREFIX}/lib
	${LN} -sf libuu.so.${SHLIB_VER} ${PREFIX}/lib/libuu.so
	${INSTALL_DATA} ${WRKSRC}/uulib/libuu.a ${PREFIX}/lib
	@/usr/bin/ranlib ${PREFIX}/lib/libuu.a
	${INSTALL_DATA} ${WRKSRC}/uulib/uudeview.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKDIR}/uulib.3 ${MANPREFIX}/man/man3
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/porting.notes ${DOCSDIR}
.for docfile in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
