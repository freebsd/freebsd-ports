# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.70
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://lame.sourceforge.net/download/beta/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	yoshiaki@kt.rim.or.jp

EXTRA_PATCHES=	${WRKDIR}/patch-lib_version
USE_GMAKE=	yes
WANT_GTK=	yes
ALL_TARGET=	lame
INSTALLS_SHLIB=	yes
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"

LIB_VERSION=	1

MAN1=		lame.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
.endif

pre-patch:
	@${SED} "s!%%LIB_VERSION%%!${LIB_VERSION}!g" \
		${FILESDIR}/template-extra-patch-lib_version \
			> ${WRKDIR}/patch-lib_version

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libmp3lame.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/libmp3lame.so.${LIB_VERSION} ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/lame.h ${PREFIX}/include
	@${INSTALL_PROGRAM} ${WRKSRC}/lame ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/man/lame.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lame
	@${INSTALL_DATA} ${WRKSRC}/doc/html/*.html \
		${WRKSRC}/doc/html/*.css ${PREFIX}/share/doc/lame
.endif

post-install:
	@${LN} -sf libmp3lame.so.${LIB_VERSION} ${PREFIX}/lib/libmp3lame.so

.include <bsd.port.post.mk>
