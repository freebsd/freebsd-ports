# Created by: Karsten Pedersen <kpedersen@opencde.org>
# $FreeBSD$

PORTNAME=	radare2
PORTVERSION=	2.0.1
CATEGORIES=	devel

MAINTAINER=	torres.73a@gmail.com
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS+=		pkg-config:devel/pkgconf
LIB_DEPENDS+=		libcapstone.so:devel/capstone4

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips mips64 powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	does not build: Unsupported BSD architecture

CONFIGURE_ARGS+=	--with-syscapstone

USES=		gmake pathfix pkgconfig tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	radare
PATHFIX_MAKEFILEIN=	Makefile
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAKE_ENV+=	HOST_CC=${CC}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

post-patch:
	${ECHO_CMD} 'CFLAGS+=-I${LOCALBASE}/include' >> ${WRKSRC}/libr/anal/Makefile
	${ECHO_CMD} 'CFLAGS+=-I${LOCALBASE}/include' >> ${WRKSRC}/libr/asm/Makefile

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's| install-doc ||g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
