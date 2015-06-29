# Created by: patrick
# $FreeBSD$

PORTNAME=	pfe
PORTVERSION=	0.33.71
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

BROKEN_i386=	does not link

GNU_CONFIGURE=	yes
USES=		gmake perl5 libtool tar:bzip2
USE_PERL5=	build
USE_LDCONFIG=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
INSTALL_TARGET=	install-strip

BROKEN_powerpc=	does not compile

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|-O$$opt_level||g' ${WRKSRC}/pfe/configure

post-install:
	@test -d "${STAGEDIR}" && ${RM} -rf ${STAGEDIR}/usr/ports
	${LN} -s libpfe-0-forth.so.33 ${STAGEDIR}${PREFIX}/lib/libpfe-0-forth.so

.include <bsd.port.mk>
