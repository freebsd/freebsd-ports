PORTNAME=	radare2
DISTVERSION=	6.0.4
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files
WWW=		https://www.radare.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.md

NOT_FOR_ARCHS=	armv6 armv7 powerpcspe
NOT_FOR_ARCHS_REASON=	does not build: Unsupported BSD architecture

LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libquickjs.so:lang/quickjs

USES=		cpe gmake localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	radare
PATHFIX_MAKEFILEIN=	Makefile
USE_GITHUB=	yes
GH_ACCOUNT=	radareorg
GH_TUPLE=	radareorg:sdb:2.2.0:sdb/subprojects/sdb \
		quickjs-ng:quickjs:7238ee64dbc2fbdea044555cda8cda78785a93ed:qjs/subprojects/qjs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-syscapstone

MAKE_ENV+=	HOST_CC=${CC}

CFLAGS+=	-I${PREFIX}/include/capstone

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
			MAJOR_VERSION="${PORTVERSION:R}"

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
