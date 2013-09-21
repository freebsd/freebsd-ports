# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	11.1
CATEGORIES=	converters
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	BSD licensed charset/encoding converter library

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	8ccd7e3

OPTIONS_DEFINE=	CHINESE EBCDIC
CHINESE_DESC=	Extra Chinese codecs
EBCDIC_DESC=	EBCDIC codecs

NO_STAGE=	yes
USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX=${PREFIX}

ALL_TARGET=	libbsdconv bsdconv-mktable meta bsdconv-man bsdconv-completion bsdconv codecs_basic
INSTALL_TARGET=	installdir install_main install_basic

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHINESE}
ALL_TARGET+=	codecs_chinese
INSTALL_TARGET+=install_chinese
PLIST_SUB+=	CHINESE=""
.else
PLIST_SUB+=	CHINESE="@comment "
.endif

.if ${PORT_OPTIONS:MEBCDIC}
ALL_TARGET+=	codecs_ebcdic
INSTALL_TARGET+=install_ebcdic
PLIST_SUB+=	EBCDIC=""
.else
PLIST_SUB+=	EBCDIC="@comment "
.endif

pre-install:
	${MKDIR} ${DATADIR}/ ${DATADIR}/from/ ${DATADIR}/inter/ ${DATADIR}/to/

.include <bsd.port.mk>
