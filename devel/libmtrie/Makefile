# New ports collection makefile for:	libmtrie
# Date created:				07 May 2003
# Whom:					alfred@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libmtrie
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/$(PORTNAME)/
DISTNAME=	$(PORTNAME)-${PORTVERSION}
USE_BZIP2=	yes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to build an IP-netmask based mtrie

USE_LDCONFIG= yes

.if defined(NOPROFILE)
PLIST_SUB+=     HURRRR="@comment "
.else
PLIST_SUB+=     HURRRR=""
.endif

.include <bsd.port.mk>
