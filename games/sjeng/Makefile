# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	sjeng
PORTVERSION=	11.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://sjeng.org/ftp/
DISTNAME=	Sjeng-Free-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chess engine supporting chess variations

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgdbm

PLIST_FILES=	bin/sjeng

.include <bsd.port.mk>
