# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	libjit
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	SAVANNAH/dotgnu-pnet/libjit-releases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libjit implements Just-In-Time compilation functionality

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		pathfix gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-O0
INSTALL_TARGET=	install-strip

INFO=		libjit

DEPRECATED=		This version is severely out of date and its use is discouraged; see http://www.gnu.org/software/libjit/
EXPIRATION_DATE=	2017-02-13

BROKEN_aarch64=		Fails to compile: error: use of unknown builtin __builtin_apply_args
BROKEN_powerpc=		Fails to compile: invokes i386 asm
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Fails to compile: internal gcc error
BROKEN_i386=		Segfault during build

post-patch:
	@${REINPLACE_CMD} -e 's|#undef HAVE_TGMATH_H||' \
		${WRKSRC}/config.h.in

.include <bsd.port.mk>
