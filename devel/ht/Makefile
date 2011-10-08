# Ports collection makefile for:	hte
# Date created:				01 Oct 2011
# Whom:					Eygene Ryabinkin
#
# $FreeBSD$
#

PORTNAME=	ht
PORTVERSION=	2.0.18
CATEGORIES=	devel
MASTER_SITES=	SF/hte/${PORTNAME}-source/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Editor/viewer/analyzer for executables

LIB_DEPENDS=	lzo2:${PORTSDIR}/archivers/lzo2

USE_NCURSES=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release --disable-x11-textmode
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
CXXLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/ht

.include <bsd.port.mk>
