# $FreeBSD$

PORTNAME=	liblpm
PORTVERSION=	g2019052401
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Longest Prefix Match library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		compiler gmake libtool:build

USE_GITHUB=	yes
GH_ACCOUNT=	rmind
GH_PROJECT=	liblpm
GH_TAGNAME=	984ac5f
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes
MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX} \
		INCDIR=${LOCALBASE}/include \
		LIBDIR=${LOCALBASE}/lib \
		MANDIR=${LOCALBASE}/man

PLIST_FILES=	include/lpm.h \
		lib/liblpm.a \
		lib/liblpm.so \
		lib/liblpm.so.1 \
		lib/liblpm.so.1.0.0

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-Makefile
.endif

.include <bsd.port.post.mk>
