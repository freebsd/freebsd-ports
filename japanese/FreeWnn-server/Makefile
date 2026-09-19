PORTNAME=	FreeWnn
PORTVERSION=	1.1.1.a021
PORTREVISION=	15
CATEGORIES?=	japanese
MASTER_SITES=	https://mirror.math.princeton.edu/pub/gentoo/distfiles/ \
		http://mirror.linux.ro/gentoo/distfiles/
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}-1.1.1-a021

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Japanese/Chinese/Korean input method (Japanese server)
WWW=		https://www.tomo.gr.jp/FreeWnn/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFAULT?=	WNN SERVER
MANLANG?=		ja
USERS=			wnn

.include "${.CURDIR}/../../japanese/FreeWnn-lib/Makefile.common"

WNN_LIB_DEPENDS+=	libwnn.so:japanese/FreeWnn-lib
WNN_CONFIGURE_ON+=	--with-libwnn=-lwnn \
			--with-wnn-libraries="${PREFIX}/lib"
WNN_USE=	RC_SUBR=wnn

CWNN_LIB_DEPENDS+=	libcwnn.so:chinese/FreeWnn-lib
CWNN_CONFIGURE_ON+=	--with-libcwnn=-lcwnn \
			--with-cwnn-libraries="${PREFIX}/lib"
CWNN_USE=	RC_SUBR=cwnn RC_SUBR=twnn

KWNN_LIB_DEPENDS+=	libkwnn.so:korean/FreeWnn-lib
KWNN_CONFIGURE_ON+=	--with-libkwnn=-lkwnn \
			--with-kwnn-libraries="${PREFIX}/lib"
KWNN_USE=	RC_SUBR=kwnn

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
