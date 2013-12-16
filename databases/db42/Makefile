# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	db42
PORTVERSION=	4.2.52
PORTREVISION=	5
CATEGORIES=	databases
PKGNAMESUFFIX?=

PATCHFILES=	patch.${PORTVERSION}.1  patch.${PORTVERSION}.2 \
		patch.${PORTVERSION}.3  patch.${PORTVERSION}.4 \
		patch.${PORTVERSION}.5

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Berkeley DB package, revision 4.2

DEPRECATED=	Please use databases/db5 or db6 for new installs.

CONFLICTS?=	db42-nocrypto-4*

MASTERDIR?=	${.CURDIR}

SLAVE_PORT=	no

NO_STAGE=	yes
.include <${MASTERDIR}/Makefile.db>
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-mutex=x86/gcc-assembly
.endif

.include <bsd.port.post.mk>
