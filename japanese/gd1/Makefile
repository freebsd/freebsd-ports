# New ports collection makefile for:	gd
# Version required:			1.3+kanji.patch
# Date created:				19 Aug 1998
# Whom:					ichiro@ichiro.org
#
# $FreeBSD$
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

BUILD_DEPENDS=	${PREFIX}/lib/libVFlib2.so:${PORTSDIR}/japanese/vflib

RESTRICTED=	unavailable from master site due to legal problems

FETCH_BEFORE_ARGS=	-b

.include <bsd.port.pre.mk>

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

do-install:
	for i in libgd.a libgd.so.1; do \
		${INSTALL} -c -o bin -g bin -m 555 ${WRKSRC}/$$i \
			${PREFIX}/lib; \
	done
	( cd ${PREFIX}/lib; ${LN} -sf libgd.so.1 libgd.so )
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

.include <bsd.port.post.mk>
