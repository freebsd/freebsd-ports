# Created by: alfred@FreeBSD.org
# $FreeBSD$

PORTNAME=	libmtrie
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/ \
		http://people.freebsd.org/~alfred/sources/${PORTNAME}/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Library to build an IP-netmask based mtrie

LICENSE=	BSD

USE_BZIP2=	yes
USE_LDCONFIG=	yes

.if defined(NO_PROFILE)
PLIST_SUB+=	HURRRR="@comment "
.else
PLIST_SUB+=	HURRRR=""
.endif

.include <bsd.port.mk>
