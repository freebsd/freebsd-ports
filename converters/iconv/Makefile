# Created by: Konstantin Chuguev <Konstantin.Chuguev@dante.org.uk>
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bland

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Charset conversion library and utilities

USES=		shebangfix
USE_PERL5=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	iconv_builtin ccs/iconv_mktbl

MANCOMPRESSED=	yes
MAN1=		biconv.1
MAN3=		biconv.3 biconv_open.3 biconv_close.3

.if defined(NO_PROFILE) || defined(NOPROFILE) || defined(WITHOUT_PROFILE)
PLIST_SUB=	PROFILE:="@comment "
.else
PLIST_SUB=	PROFILE:=""
.endif

.include <bsd.port.mk>
