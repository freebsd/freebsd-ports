PORTNAME=	FreeWnn
PORTVERSION=	1.1.1.a021
PORTREVISION=	14
CATEGORIES?=	japanese
MASTER_SITES=	OSDN/freewnn
PKGNAMESUFFIX=	-lib
DISTNAME=	${PORTNAME}-1.1.1-a021

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Japanese/Chinese/Korean input method (Japanese client libraries)
WWW=		http://freewnn.osdn.jp/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USE_LDCONFIG=	yes

OPTIONS_DEFAULT?=	LIB WNN
MANLANG?=		ja

.include "${.CURDIR}/../../japanese/FreeWnn-lib/Makefile.common"
.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
