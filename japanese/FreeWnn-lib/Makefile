# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FreeWnn
PORTVERSION=	1.1.1.a021
PORTREVISION=	10
CATEGORIES?=	japanese
MASTER_SITES=	ftp://ftp.freewnn.org/pub/%SUBDIR%/ \
		${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	FreeWnn/alpha \
			freewnn/17724
PKGNAMESUFFIX=	-lib
DISTNAME=	${PORTNAME}-1.1.1-a021

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Japanese/Chinese/Korean input method (Japanese client libraries)

OPTIONS_DEFAULT?=	LIB WNN
MANLANG?=		ja

.include "${.CURDIR}/../../japanese/FreeWnn-lib/Makefile.common"
.include <bsd.port.mk>
