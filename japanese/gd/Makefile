# New ports collection makefile for:	gd
# Version required:			1.3+kanji.patch
# Date created:				19 Aug 1998
# Whom:					ichiro@ichiro.org
#
# $Id: Makefile,v 1.2 1998/10/06 20:52:44 asami Exp $
#

DISTNAME=	gd1.3
PKGNAME=	ja-gd-1.3
CATEGORIES=	japanese graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

PATCH_SITES=	http://pg.cni.co.jp/GD/
PATCHFILES=	gd1.3.kanji.patch-fix1.gz
PATCH_DIST_STRIP=	# empty

MAINTAINER=	ichiro@ichiro.org

BUILD_DEPENDS=	${PREFIX}/lib/libVFlib2.a:${PORTSDIR}/japanese/vflib

BROKEN_ELF=	linker command line

FETCH_BEFORE_ARGS=	-b

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

do-install:
	for i in libgd.a libgd.so.1.3; do \
		${INSTALL} -c -o bin -g bin -m 555 ${WRKSRC}/$$i \
			${PREFIX}/lib; \
	done
	if [ "${PORTOBJFORMAT}" = "aout" ]; then \
		(cd ${PREFIX}/lib; ${LN} -sf libgd.so.1.3 libgd.so); \
	else \
		(cd ${PREFIX}/lib; ${MV} -sf libgd.so.1.3 libgd.so.1; \
		${LN} -sf libgd.so.1 libgd.so); \
	fi
	for i in gddemo giftogd webgif; do \
	${INSTALL} -c -o bin -g bin -m 755 ${WRKSRC}/$$i \
		${PREFIX}/bin; \
	done
	for i in gd.h gdfontt.h gdfonts.h gdfontmb.h gdfontl.h gdfontg.h; do \
		${INSTALL} -c -o root -g bin -m 644 ${WRKSRC}/$$i \
			${PREFIX}/include/gd; \
	done
	for i in index.html demoin.gif ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i \
			${PREFIX}/share/examples/gd; \
	done

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
