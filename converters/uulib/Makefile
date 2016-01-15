# Created by: Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
# $FreeBSD$

PORTNAME=	uulib
PORTVERSION=	0.5.20
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/
DISTNAME=	uudeview-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for uu/xx/Base64/BinHex/yEnc de-/encoding

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
ALL_TARGET=	libuu.a	libuu.so.${SHLIB_VER}
USE_LDCONFIG=	yes

PORTDOCS=	*
PLIST_FILES=	include/uudeview.h lib/libuu.a lib/libuu.so \
		lib/libuu.so.${SHLIB_VER} \
		man/man3/uulib.3.gz

SHLIB_VER=	3

DOCFILES=	HISTORY doc/Makefile doc/README doc/binhex.fig \
		doc/library.ltx doc/structure.fig doc/td-v1.c doc/td-v2.c \
		doc/td-v3.c doc/test.txt

post-patch:
	@${SED} -e 's,FUNKYTOKENHERE,${PREFIX}/,' \
		< ${FILESDIR}/uulib.3 > ${WRKDIR}/uulib.3

do-install:
	${INSTALL_LIB} ${WRKSRC}/uulib/libuu.so.${SHLIB_VER} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libuu.so.${SHLIB_VER} ${STAGEDIR}${PREFIX}/lib/libuu.so
	${INSTALL_DATA} ${WRKSRC}/uulib/libuu.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/uulib/uudeview.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKDIR}/uulib.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/porting.notes ${STAGEDIR}${DOCSDIR}
.for docfile in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
