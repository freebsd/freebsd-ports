# Created by: Karsten Pedersen <kpedersen@opencde.org>
# $FreeBSD$

PORTNAME=	radare2
DISTVERSION=	5.1.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	armv6 armv7 mips mips64 powerpc powerpc64 powerpc64le \
		powerpcspe riscv64 sparc64
NOT_FOR_ARCHS_REASON=	does not build: Unsupported BSD architecture

LIB_DEPENDS=	libcapstone.so:devel/capstone4

USES=		gmake localbase pathfix pkgconfig
USE_GITHUB=	yes

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
	${RM} ${WRKSRC}/libr/flag/d/Makefile.bak

.include <bsd.port.mk>
