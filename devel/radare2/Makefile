# Created by: Karsten Pedersen <kpedersen@opencde.org>

PORTNAME=	radare2
DISTVERSION=	5.1.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	armv6 armv7 mips mips64 powerpcspe sparc64
NOT_FOR_ARCHS_REASON=	does not build: Unsupported BSD architecture

LIB_DEPENDS=	libcapstone.so:devel/capstone4

USES=		cpe gmake localbase pathfix pkgconfig
USE_GITHUB=	yes

CPE_VENDOR=	radare

CONFIGURE_ARGS=	--with-syscapstone
CFLAGS+=	-I${PREFIX}/include/capstone
GH_ACCOUNT=	radare
PATHFIX_MAKEFILEIN=	Makefile
GNU_CONFIGURE=	yes

MAKE_ENV+=	HOST_CC=${CC}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile

# libr/flag/d/Makefile generates an r2 script from all files in
# current directory, including .bak file left by ${REINPLACE_CMD}
# called by pathfix.
post-patch:
	${CP} ${WRKSRC}/libr/debug/p/native/linux/reg/linux-ppc.h \
		${WRKSRC}/libr/debug/p/native/reg/kfbsd-ppc.h
	${CP} ${WRKSRC}/libr/debug/p/native/linux/reg/linux-ppc64.h \
		${WRKSRC}/libr/debug/p/native/reg/kfbsd-ppc64.h
	${CP} ${WRKSRC}/libr/debug/p/native/linux/reg/linux-riscv64.h \
		${WRKSRC}/libr/debug/p/native/reg/kfbsd-riscv64.h
	${RM} ${WRKSRC}/libr/flag/d/Makefile.bak

.include <bsd.port.mk>
