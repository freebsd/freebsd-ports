# $FreeBSD$

PORTNAME=	liblpm
PORTVERSION=	g2020082801
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Longest Prefix Match library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		compiler:c11 gmake libtool:build

USE_GITHUB=	yes
GH_ACCOUNT=	rmind
GH_PROJECT=	liblpm
GH_TAGNAME=	4119bb7
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

.include <bsd.port.mk>
