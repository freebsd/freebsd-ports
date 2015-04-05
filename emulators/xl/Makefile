# $FreeBSD$

PORTNAME=	xl
PORTVERSION=	4.5.0
CATEGORIES=	emulators
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/ \
		http://code.coreboot.org/p/seabios/downloads/get/:seabios

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Xen management tool, based on LibXenlight

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	multi

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCH=	amd64

LIB_DEPENDS=	libyajl.so:${PORTSDIR}/devel/yajl \
		liblzo2.so:${PORTSDIR}/archivers/lzo2
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	/boot/xen:${PORTSDIR}/emulators/xen

CONFIGURE_ARGS=	--disable-xen

SEABIOSVERSION=	1.8.1
DISTFILES+=	xen-${PORTVERSION}.tar.gz \
		seabios-${SEABIOSVERSION}.tar.gz:seabios

WRKSRC=		${WRKDIR}/xen-${PORTVERSION}

USES=		gmake perl5 python shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	HOSTCC="${CC}" CC="${CC}" \
		ac_cv_path_BASH=${TRUE} \
		ac_cv_path_XGETTEXT=${TRUE} \
		glib_CFLAGS=" " glib_LIBS=" "
MAKE_ARGS=	HOSTCC="${CC}" CC="${CC}"
SHEBANG_FILES=	tools/misc/xencov_split \
		tools/misc/xen-ringwatch
USE_GCC=	yes
ALL_TARGET=	tools docs
INSTALL_TARGET=	install-tools install-docs

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		Only supported on FreeBSD
.endif

.if ${OSVERSION} < 1100055
IGNORE=		Only supported on recent FreeBSD 11
.endif

post-extract:
	${MV} ${WRKDIR}/seabios-${SEABIOSVERSION} ${WRKSRC}/tools/firmware/seabios-dir

post-patch:
	@${REINPLACE_CMD} -e "s,/var/lib,/var/db,g" \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/tools/libxc/include/xenguest.h \
		${WRKSRC}/tools/libxl/libxl_dom.c \
		${WRKSRC}/tools/libxl/libxl_dm.c \
		${WRKSRC}/tools/qemu-xen-traditional/i386-dm/helper2.c \
		${WRKSRC}/docs/man/*

.include <bsd.port.mk>
RUN_DEPENDS:=	${RUN_DEPENDS:N*gcc*}
