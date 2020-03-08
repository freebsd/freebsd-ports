# Created by: Alexander Botero-Lowry <alexbl@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	3
CATEGORIES=	audio perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Perl Bindings for XMMS2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS+=	libxmmsclient.so:audio/xmms2

MASTERDIR=	${.CURDIR}/../xmms2

USES=		perl5 python:2.7,build ssl

BROKEN_SSL=	openssl

PLIST=		${.CURDIR}/pkg-plist

XMMS2_SLAVE=	perl

.include "${MASTERDIR}/Makefile"
