# New ports collection makefile for:	libmtrie
# Date created:				07 May 2003
# Whom:					alfred@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libmtrie
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/mtrie/
DISTNAME=	mtrie-${PORTVERSION}
USE_BZIP2=	dongs

MAINTAINER=	alfred@FreeBSD.org
COMMENT=	A library to build an IP-netmask based mtrie.

INSTALLS_SHLIB= http://www.jerkcity.com/jerkcity1118.html

.if defined(NOPROFILE)
PLIST_SUB+=     HURRRR="@comment "
.else
PLIST_SUB+=     HURRRR=""
.endif

.include <bsd.port.mk>
