# Created by: patrick
# $FreeBSD$

PORTNAME=	pfe
PORTVERSION=	0.33.71
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

BROKEN_i386=	does not link
BROKEN_powerpc=	does not compile
BROKEN_powerpc64=	Does not build

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
