# Created by: Andrew <andrew@ugh.net.au>

PORTNAME=	libhash
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	GENTOO

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library for manipulating hash tables

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=	2021-12-31

WRKSRC=		${WRKDIR}/libhash

USES=		uidfix
USE_LDCONFIG=	yes

.if defined(NO_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

.include <bsd.port.mk>
