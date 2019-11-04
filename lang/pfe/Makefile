# Created by: patrick
# $FreeBSD$

PORTNAME=	pfe
PORTVERSION=	0.33.71
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

BROKEN_aarch64=		fails to compile: implicit declaration of function 'PFE_SBR_COMPILE_EXIT' is invalid in C99
BROKEN_armv6=		fails to compile: implicit declaration of function 'PFE_SBR_COMPILE_EXIT' is invalid in C99
BROKEN_armv7=		fails to compile: implicit declaration of function 'PFE_SBR_COMPILE_EXIT' is invalid in C99
BROKEN_i386=		fails to link
BROKEN_powerpc=		fails to compile
BROKEN_powerpc64=	fails to build: lvalue required as increment operand

GNU_CONFIGURE=	yes
USES=		gmake perl5 libtool tar:bzip2
USE_PERL5=	build
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-testmodule
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|-O$$opt_level||g' ${WRKSRC}/pfe/configure

post-install:
	${LN} -s libpfe-0-forth.so.33 ${STAGEDIR}${PREFIX}/lib/libpfe-0-forth.so

.include <bsd.port.mk>
