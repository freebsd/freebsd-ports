# Created by: Karsten Pedersen <kpedersen@opencde.org>
# $FreeBSD$

PORTNAME=	radare2
PORTVERSION=	0.9.8
CATEGORIES=	devel
MASTER_SITES=	http://rada.re/get/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake tar:xz
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--without-ewf --without-gmp
MAKE_ENV+=	HOST_CC=${CC}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|..LIBDIR./pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|..LFX./pkgconfig|${STAGEDIR}${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/libr/Makefile
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's| install-doc install-man||g' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
