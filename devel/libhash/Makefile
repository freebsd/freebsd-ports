# Created by: Andrew <andrew@ugh.net.au>
# $FreeBSD$

PORTNAME=	libhash
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library for manipulating hash tables

WRKSRC=		${WRKDIR}/libhash

USES=		uidfix
USE_LDCONFIG=	yes

.if defined(NO_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

.include <bsd.port.mk>
