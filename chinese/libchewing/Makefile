# Created by: Kuang-che Wu <kcwu@csie.org>
# $FreeBSD$

PORTNAME=	libchewing
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	chinese textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chewing intelligent phonetic input method library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

BROKEN_powerpc=	does not install on powerpc: signal 6

USES=		cmake gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	chewing

CMAKE_ARGS+=	-DMAKEINFO=${LOCALBASE}/bin/makeinfo
CFLAGS+=	-I${LOCALBASE}/include
INFO=		libchewing

.include <bsd.port.mk>
