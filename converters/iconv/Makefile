# New ports collection makefile for:	iconv
# Date created:				21 September 1999
# Whom:			Konstantin Chuguev <Konstantin.Chuguev@dante.org.uk>
#
# $FreeBSD$
#

PORTNAME=	iconv
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.dante.net/staff/konstantin/FreeBSD/iconv/

MAINTAINER=	Konstantin.Chuguev@dante.org.uk

USE_PERL5=	yes
INSTALLS_SHLIB=	yes

MANCOMPRESSED=	yes
MAN1=		iconv.1
MAN3=		iconv.3 iconv_open.3 iconv_close.3

.if defined(NOPROFILE)
PLIST_SUB=	PROFILE:="@comment "
.else
PLIST_SUB=	PROFILE:=""
.endif

.include <bsd.port.mk>
