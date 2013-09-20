# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cxxtools
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Collection of general-purpose C++ classes

PATCH_STRIP=	-p1
USES=		iconv
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
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

.include <bsd.port.post.mk>
