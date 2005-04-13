# ports collection makefile for:	Berkeley DB v4.2
# Date created:				2003-11-26
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	db42
PORTVERSION=	4.2.52
PORTREVISION=	4
CATEGORIES=	databases
PKGNAMESUFFIX?=

PATCHFILES=	patch.${PORTVERSION}.1  patch.${PORTVERSION}.2 \
		patch.${PORTVERSION}.3  patch.${PORTVERSION}.4

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	The Berkeley DB package, revision 4.2

MASTERDIR?=	${.CURDIR}

SLAVE_PORT=	no

.include <${MASTERDIR}/Makefile.db>
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-mutex=x86/gcc-assembly
.endif

.include <bsd.port.post.mk>
