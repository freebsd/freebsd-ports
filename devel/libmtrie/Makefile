# Created by: alfred@FreeBSD.org
# $FreeBSD$

PORTNAME=	libmtrie
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/$(PORTNAME)/
DISTNAME=	$(PORTNAME)-${PORTVERSION}
USE_BZIP2=	yes

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Library to build an IP-netmask based mtrie

USE_LDCONFIG= yes

.if defined(NO_PROFILE)
PLIST_SUB+=     HURRRR="@comment "
.else
PLIST_SUB+=     HURRRR=""
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
