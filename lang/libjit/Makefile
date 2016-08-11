# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	libjit
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SAVANNAH/dotgnu-pnet/libjit-releases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libjit implements Just-In-Time compilation functionality

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BROKEN_powerpc64=	Does not build

USES=		pathfix gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-O0
INSTALL_TARGET=	install-strip

INFO=		libjit

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Segfault during build
.elif ${ARCH} == "powerpc"
BROKEN=		Fails to compile: invokes i386 asm
.elif ${ARCH} == "sparc64"
BROKEN=		Fails to compile: internal gcc error
.elif ${ARCH} == i386 && ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
BROKEN=		Segfault during build
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#undef HAVE_TGMATH_H||' \
		${WRKSRC}/config.h.in

.include <bsd.port.post.mk>
