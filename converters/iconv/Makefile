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
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	iconv_builtin ccs/iconv_mktbl

MANCOMPRESSED=	yes
MAN1=		biconv.1
MAN3=		biconv.3 biconv_open.3 biconv_close.3

OPTIONS_DEFINE=	CCSUTIL
OPTIONS_DEFAULT=CCSUTIL

OPTIONS_SUB=	yes

CCSUTIL_DESC=	Install Coded character set (CCS) util

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCCSUTIL}
USE_PERL5_RUN=	yes
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ccs_Makefile
.endif

.include <bsd.port.mk>
