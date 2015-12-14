# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cxxtools
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of general-purpose C++ classes

LICENSE=	LGPL21 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

PATCH_STRIP=	-p1
USES=		cpe iconv libtool pathfix
CPE_VENDOR=	tntnet
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif
.if ${ARCH} == "amd64"
PLIST_SUB+=	X86_64_ONLY=""
.else
PLIST_SUB+=	X86_64_ONLY="@comment "
.endif
.if ${ARCH} == "i386"
PLIST_SUB+=	I386_ONLY=""
.else
PLIST_SUB+=	I386_ONLY="@comment "
.endif
.if (${ARCH} == "amd64") || (${ARCH} == "i386")
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif
.if ${ARCH} == "arm" || ${ARCH} == "armv6"
PLIST_SUB+=	ARM_ONLY=""
.else
PLIST_SUB+=	ARM_ONLY="@comment "
.endif
.if ${ARCH} == "mips" || ${ARCH} == "mips64"
PLIST_SUB+=	MIPS_ONLY=""
.else
PLIST_SUB+=	MIPS_ONLY="@comment "
.endif
.if ${ARCH} == "powerpc" || ${ARCH} == "powerpc64"
PLIST_SUB+=	PPC_ONLY=""
.else
PLIST_SUB+=	PPC_ONLY="@comment "
.endif

.include <bsd.port.post.mk>
