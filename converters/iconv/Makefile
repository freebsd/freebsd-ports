# Created by: Konstantin Chuguev <Konstantin.Chuguev@dante.org.uk>
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	LOCAL/bland

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Charset conversion library and utilities

USES=		shebangfix perl5 uidfix
USE_PERL5=	build
USE_LDCONFIG=	yes
SHEBANG_FILES=	iconv_builtin ccs/iconv_mktbl

OPTIONS_DEFINE=	CCSUTIL
OPTIONS_DEFAULT=CCSUTIL

OPTIONS_SUB=	yes

CCSUTIL_DESC=	Install Coded character set (CCS) util

CCSUTIL_USE=	PERL5=run
CCSUTIL_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-ccs_Makefile

.if defined(NO_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

.include <bsd.port.mk>
