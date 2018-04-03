# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	11.5
PORTREVISION=	1
CATEGORIES=	converters

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

LICENSE=	ISCL

USE_GITHUB=	yes
GH_ACCOUNT=	buganini

OPTIONS_DEFINE=	CHINESE EBCDIC
OPTIONS_SUB=	yes
CHINESE_DESC=	Extra Chinese codecs
EBCDIC_DESC=	EBCDIC codecs

ALL_TARGET=	libbsdconv bsdconv-mktable meta bsdconv-man bsdconv-completion bsdconv filters scorers codecs_basic
INSTALL_TARGET=	installdir install_main install_filters install_scorers install_basic
MAKE_ARGS=	PREFIX=${PREFIX} STRIP=${STRIP}
USE_LDCONFIG=	yes
USES=		gmake

CHINESE_ALL_TARGET=	codecs_chinese
CHINESE_INSTALL_TARGET=	install_chinese
EBCDIC_ALL_TARGET=	codecs_ebcdic
EBCDIC_INSTALL_TARGET=	install_ebcdic

.include <bsd.port.mk>
