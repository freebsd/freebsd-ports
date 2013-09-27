# Created by: stas@FreeBSD.org
# $FreeBSD$

PORTNAME=	libunwind
PORTVERSION=	20121006	# This is actually official libunwind 1.1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH
DISTNAME=	${PORTNAME}-1.1

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Generic stack unwinding library

ONLY_FOR_ARCHS=	i386 amd64

USES=	pkgconfig pathfix
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize libtool
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-c -a
LIBTOOLFILES=	#empty

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLIST_SUB=	ARCH=x86
.elif ${ARCH} == amd64
PLIST_SUB=	ARCH=x86_64
.endif

.include <bsd.port.post.mk>
