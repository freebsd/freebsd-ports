# New ports collection makefile for:	iconv
# Date created:				21 September 1999
# Whom:			Konstantin Chuguev <Konstantin.Chuguev@dante.org.uk>
#
# $FreeBSD$
#

PORTNAME=	iconv
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bland

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Charset conversion library and utilities

USE_PERL5=	yes
USE_LDCONFIG=	yes

MANCOMPRESSED=	yes
MAN1=		biconv.1
MAN3=		biconv.3 biconv_open.3 biconv_close.3

.if defined(NO_PROFILE) || defined(NOPROFILE) || defined(WITHOUT_PROFILE)
PLIST_SUB=	PROFILE:="@comment "
.else
PLIST_SUB=	PROFILE:=""
.endif

.include <bsd.port.mk>
