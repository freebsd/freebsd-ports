# ports collection makefile for:	Berkeley DB v4.3
# Date created:				2004-11-10
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	db43
PORTVERSION=	4.3.21
CATEGORIES=	databases
PKGNAMESUFFIX?=

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	The Berkeley DB package, revision 4.3

MASTERDIR?=	${.CURDIR}

.include <${MASTERDIR}/Makefile.db>
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-mutex=x86/gcc-assembly
.endif

.include <bsd.port.post.mk>
