# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FreeWnn
PORTVERSION=	1.1.1.a021
PORTREVISION=	10
CATEGORIES?=	japanese
MASTER_SITES=	ftp://ftp.freewnn.org/pub/%SUBDIR%/ \
		${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	FreeWnn/alpha \
			freewnn/17724
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}-1.1.1-a021

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Japanese/Chinese/Korean input method (Japanese server)

OPTIONS_DEFAULT?=	WNN SERVER
MANLANG?=		ja
USERS=			wnn

.include "${.CURDIR}/../../japanese/FreeWnn-lib/Makefile.common"

WNN_LIB_DEPENDS+=	libwnn.so:${PORTSDIR}/japanese/FreeWnn-lib
WNN_CONFIGURE_ON+=	--with-libwnn=-lwnn \
			--with-wnn-libraries="${PREFIX}/lib"
WNN_USE=	RC_SUBR=wnn

CWNN_LIB_DEPENDS+=	libcwnn.so:${PORTSDIR}/chinese/FreeWnn-lib
CWNN_CONFIGURE_ON+=	--with-libcwnn=-lcwnn \
			--with-cwnn-libraries="${PREFIX}/lib"
CWNN_USE=	RC_SUBR=cwnn RC_SUBR=twnn

KWNN_LIB_DEPENDS+=	libkwnn.so:${PORTSDIR}/korean/FreeWnn-lib
KWNN_CONFIGURE_ON+=	--with-libkwnn=-lkwnn \
			--with-kwnn-libraries="${PREFIX}/lib"
KWNN_USE=	RC_SUBR=kwnn

.include <bsd.port.mk>
