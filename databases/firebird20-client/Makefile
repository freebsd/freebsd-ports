# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	firebird
PORTREVISION=	0
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}-client

COMMENT=	Firebird-2 database client

MASTERDIR=	${.CURDIR}/../firebird20-server

PLIST=		${PKGDIR}/pkg-plist.client

CLIENT_ONLY=	yes

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
