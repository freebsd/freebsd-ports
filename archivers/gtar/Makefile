# New ports collection makefile for:	gtar
# Date created:		Sa   6 Jun 1998 10:24:51 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	tar
PORTVERSION=	1.13.19
PKGNAMEPREFIX=	g
CATEGORIES=	archivers sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/tar/ \
		ftp://ftp.sunsite.org.uk/Mirrors/alpha.gnu.org/gnu/tar/ \
		ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/tar/

MAINTAINER=	naddy@mips.inka.de

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		DEFAULT_ARCHIVE='/dev/sa0'

.if defined(WANT_STATIC)
CONFIGURE_ENV+=	LDFLAGS='-L${LOCALBASE}/lib -static'
.else
CONFIGURE_ENV+=	LDFLAGS='-L${LOCALBASE}/lib'
.endif

.include <bsd.port.mk>
