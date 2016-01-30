# Created by: Karsten Pedersen <kpedersen@opencde.org>
# $FreeBSD$

PORTNAME=	radare2
PORTVERSION=	0.9.9
CATEGORIES=	devel
MASTER_SITES=	http://rada.re/get/

MAINTAINER=	torres.73a@gmail.com
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS+=	libcapstone.so:${PORTSDIR}/devel/capstone

CONFIGURE_ARGS+=	--with-syscapstone

GNU_CONFIGURE=	yes
USES=		gmake tar:xz
USE_LDCONFIG=	yes

MAKE_ENV+=	HOST_CC=${CC}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|..LIBDIR./pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|..LFX./pkgconfig|${STAGEDIR}${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/libr/Makefile
	@${ECHO_CMD} 'CFLAGS+=-I${LOCALBASE}/include' >> ${WRKSRC}/libr/anal/Makefile
	@${ECHO_CMD} 'CFLAGS+=-I${LOCALBASE}/include' >> ${WRKSRC}/libr/asm/Makefile

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's| install-doc ||g' \
		${WRKSRC}/Makefile

post-install:
	@${RMDIR} ${STAGEDIR}/${DATADIR}/${PORTVERSION}/format/dll

.include <bsd.port.mk>
