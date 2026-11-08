PORTNAME=	FreeWnn
PORTVERSION=	1.1.1.a021
PORTREVISION=	15
CATEGORIES?=	japanese
MASTER_SITES=	https://mirror.math.princeton.edu/pub/gentoo/distfiles/ \
		http://mirror.linux.ro/gentoo/distfiles/
PKGNAMESUFFIX=	-lib
DISTNAME=	${PORTNAME}-1.1.1-a021

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Japanese/Chinese/Korean input method (Japanese client libraries)
WWW=		https://www.tomo.gr.jp/FreeWnn/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USE_LDCONFIG=	yes

OPTIONS_DEFAULT?=	LIB WNN
MANLANG?=		ja

.include "${.CURDIR}/../../japanese/FreeWnn-lib/Makefile.common"
.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
